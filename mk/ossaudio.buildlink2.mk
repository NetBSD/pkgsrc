# $NetBSD: ossaudio.buildlink2.mk,v 1.11.2.2 2003/03/16 11:12:03 jmmv Exp $
#
# This file should be included by Makefiles for packages that use OSS.
# By checking the value of HAVE_OSS after including this file, it's possible
# to check whether audio/oss is installed, or if ossaudio OSS emulation
# should be used instead:
#
#	.include "../../mk/ossaudio.buildlink2.mk"
#
#	.if defined(HAVE_OSS) && (${HAVE_OSS} == "YES")
#	CONFIGURE_ENV+=		ac_cv_libossaudio__oss_ioctl=no
#	.endif
#
.if !defined(OSSAUDIO_BUILDLINK2_MK)
OSSAUDIO_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

.if defined(USE_OSS)
BUILD_DEFS+=	USE_OSS
.endif

_HAVE_OSS!=	if ${PKG_INFO} -qe oss; then ${ECHO} YES; else ${ECHO} NO; fi
HAVE_OSS?=	${_HAVE_OSS}

.if defined(HAVE_OSS) && (${HAVE_OSS} == "YES")
.  include "../../audio/oss/buildlink2.mk"
.else
BUILDLINK_PREFIX.ossaudio=	/usr
BUILDLINK_FILES.ossaudio=	include/sys/soundcard.h
BUILDLINK_FILES.ossaudio+=	include/machine/soundcard.h
BUILDLINK_FILES.ossaudio+=	lib/libossaudio.*

.  if ${OPSYS} == "NetBSD"
LIBOSSAUDIO?=			-lossaudio
DEVOSSAUDIO?=			/dev/audio
DEVOSSSOUND?=			/dev/sound
.  elif ${OPSYS} == "Linux"
LIBOSSAUDIO?=			# empty
DEVOSSAUDIO?=			/dev/dsp
DEVOSSSOUND?=			/dev/dsp
.  else
LIBOSSAUDIO?=			# empty
DEVOSSAUDIO?=			/dev/audio
DEVOSSSOUND?=			/dev/sound
.  endif
.endif

CONFIGURE_ENV+=			LIBOSSAUDIO="${LIBOSSAUDIO}"
CONFIGURE_ENV+=			DEVOSSAUDIO="${DEVOSSAUDIO}"
CONFIGURE_ENV+=			DEVOSSSOUND="${DEVOSSSOUND}"

MAKE_ENV+=			LIBOSSAUDIO="${LIBOSSAUDIO}"
MAKE_ENV+=			DEVOSSAUDIO="${DEVOSSAUDIO}"
MAKE_ENV+=			DEVOSSSOUND="${DEVOSSSOUND}"

BUILDLINK_TARGETS+=		ossaudio-buildlink
BUILDLINK_TARGETS+=		ossaudio-buildlink-soundcard-h

ossaudio-buildlink: _BUILDLINK_USE

# Many programs expect <soundcard.h> to be found as <sys/soundcard.h>.
# Also include <sys/ioctl.h> prior to include <soundcard.h> since we need
# definitions for _IOWR and friends.
#
ossaudio-buildlink-soundcard-h:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	sys_soundcard_h=${BUILDLINK_DIR}/include/sys/soundcard.h;	\
	if [ ! -f $${sys_soundcard_h} -a				\
	       -f ${BUILDLINK_PREFIX.ossaudio}/include/soundcard.h ]; then \
		${ECHO_BUILDLINK_MSG} "Creating $${sys_soundcard_h}.";	\
		${MKDIR} `${DIRNAME} $${sys_soundcard_h}`;		\
		( ${ECHO} "#ifndef BUILDLINK_SYS_SOUNDCARD_H";		\
		  ${ECHO} "#define BUILDLINK_SYS_SOUNDCARD_H";		\
		  ${ECHO} "#include <sys/ioctl.h>";			\
		  ${ECHO} "#include <soundcard.h>";			\
		  ${ECHO} "#endif";					\
		) > $${sys_soundcard_h};				\
	fi;								\
	mach_soundcard_h=${BUILDLINK_DIR}/include/machine/soundcard.h;	\
	if [ ! -f $${mach_soundcard_h} -a -f $${sys_soundcard_h} ]; then \
		${ECHO_BUILDLINK_MSG} "Creating $${mach_soundcard_h}.";	\
		${MKDIR} `${DIRNAME} $${mach_soundcard_h}`;		\
		${LN} -s $${sys_soundcard_h} $${mach_soundcard_h};	\
	fi

.endif	# OSSAUDIO_BUILDLINK2_MK
