# $NetBSD: ossaudio.buildlink2.mk,v 1.5 2002/10/03 02:56:32 jlam Exp $

.if !defined(OSSAUDIO_BUILDLINK2_MK)
OSSAUDIO_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

_OSS_INSTALLED!=	if ${PKG_INFO} -qe oss; then echo YES; else echo NO; fi

.if ${_OSS_INSTALLED} == "YES"
.  include "../../audio/oss/buildlink2.mk"
.else
BUILDLINK_PREFIX.ossaudio=	/usr
BUILDLINK_FILES.ossaudio=	include/sys/soundcard.h
BUILDLINK_FILES.ossaudio+=	include/machine/soundcard.h
BUILDLINK_FILES.ossaudio+=	lib/libossaudio.*

.  if ${OPSYS} == "NetBSD"
LIBOSSAUDIO?=			-lossaudio
DEVOSSAUDIO?=			/dev/audio
.  elif ${OPSYS} == "Linux"
LIBOSSAUDIO?=			# empty
DEVOSSAUDIO?=			/dev/dsp
.  else
LIBOSSAUDIO?=			# empty
DEVOSSAUDIO?=			/dev/audio
.  endif
.endif

MAKE_ENV+=			LIBOSSAUDIO="${LIBOSSAUDIO}"
MAKE_ENV+=			DEVOSSAUDIO="${DEVOSSAUDIO}"

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
		${LN} $${sys_soundcard_h} $${mach_soundcard_h};		\
	fi

.endif	# OSSAUDIO_BUILDLINK2_MK
