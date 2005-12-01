# $NetBSD: ossaudio.buildlink3.mk,v 1.4 2005/12/01 19:18:50 wiz Exp $
#
# This file should be included by Makefiles for packages that use OSS.
# By checking the value of HAVE_OSS after including this file, it's possible
# to check whether audio/oss is installed, or if ossaudio OSS emulation
# should be used instead:
#
#	.include "../../mk/ossaudio.buildlink3.mk"
#
#	.if defined(HAVE_OSS) && (${HAVE_OSS} == "YES")
#	CONFIGURE_ENV+=		ac_cv_libossaudio__oss_ioctl=no
#	.endif
#
OSSAUDIO_BUILDLINK3_MK:=	${OSSAUDIO_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(OSSAUDIO_BUILDLINK3_MK:M+)
.  if !defined(_HAVE_OSS)
_HAVE_OSS!=	if ${PKG_INFO} -qe oss; then ${ECHO} YES; else ${ECHO} NO; fi
MAKEFLAGS+=	_HAVE_OSS=${_HAVE_OSS}
.  endif
HAVE_OSS?=	${_HAVE_OSS}
.endif	# OSSAUDIO_BUILDLINK3_MK

.if defined(HAVE_OSS) && (${HAVE_OSS} == "YES")
.  include "../../audio/oss/buildlink3.mk"
.else
BUILDLINK_PREFIX.oss=	/usr
.  if ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD"
LIBOSSAUDIO?=		-lossaudio
DEVOSSAUDIO?=		/dev/audio
DEVOSSSOUND?=		/dev/sound
.  elif ${OPSYS} == "Linux"
LIBOSSAUDIO?=		# empty
DEVOSSAUDIO?=		/dev/dsp
DEVOSSSOUND?=		/dev/dsp
.  else
LIBOSSAUDIO?=		# empty
DEVOSSAUDIO?=		/dev/audio
DEVOSSSOUND?=		/dev/sound
.  endif
.endif

.if !empty(OSSAUDIO_BUILDLINK3_MK:M+)
CONFIGURE_ENV+=		LIBOSSAUDIO="${LIBOSSAUDIO}"
CONFIGURE_ENV+=		DEVOSSAUDIO="${DEVOSSAUDIO}"
CONFIGURE_ENV+=		DEVOSSSOUND="${DEVOSSSOUND}"

MAKE_ENV+=		LIBOSSAUDIO="${LIBOSSAUDIO}"
MAKE_ENV+=		DEVOSSAUDIO="${DEVOSSAUDIO}"
MAKE_ENV+=		DEVOSSSOUND="${DEVOSSSOUND}"

BUILDLINK_TARGETS+=	buildlink-ossaudio-soundcard-h

# Many programs expect <soundcard.h> to be found as <sys/soundcard.h>.
# Also include <sys/ioctl.h> prior to include <soundcard.h> since we need
# definitions for _IOWR and friends.
#
.PHONY: buildlink-ossaudio-soundcard-h
buildlink-ossaudio-soundcard-h:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	sys_soundcard_h=${BUILDLINK_DIR}/include/sys/soundcard.h;	\
	soundcard_h=${BUILDLINK_PREFIX.oss}/include/soundcard.h;	\
	if [ ! -f $${sys_soundcard_h} -a -f $${soundcard_h} ]; then	\
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
.endif	# OSSAUDIO_BUILDLINK3_MK
