# $NetBSD: ossaudio.buildlink2.mk,v 1.3 2002/09/26 12:31:08 jlam Exp $

.if !defined(OSSAUDIO_BUILDLINK2_MK)
OSSAUDIO_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_PREFIX.ossaudio=	/usr
BUILDLINK_FILES.ossaudio=	include/sys/soundcard.h
BUILDLINK_FILES.ossaudio+=	lib/libossaudio.*

BUILDLINK_TARGETS+=		ossaudio-buildlink
BUILDLINK_TARGETS+=		ossaudio-buildlink-soundcard-h

.if ${OPSYS} == "NetBSD"
LIBOSSAUDIO?=			-lossaudio
DEVOSSAUDIO?=			/dev/audio
.elif ${OPSYS} == "Linux"
LIBOSSAUDIO?=			# empty
DEVOSSAUDIO?=			/dev/dsp
.else
LIBOSSAUDIO?=			# empty
DEVOSSAUDIO?=			/dev/audio
.endif

MAKE_ENV+=			LIBOSSAUDIO="${LIBOSSAUDIO}"
MAKE_ENV+=			DEVOSSAUDIO="${DEVOSSAUDIO}"

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
		${ECHO_BUILDLINK_MSG} "Creating $${sys_soundcard_h}.";		\
		${MKDIR} `${DIRNAME} $${sys_soundcard_h}`;		\
		( ${ECHO} "#ifndef BUILDLINK_SYS_SOUNDCARD_H";		\
		  ${ECHO} "#define BUILDLINK_SYS_SOUNDCARD_H";		\
		  ${ECHO} "#include <sys/ioctl.h>";			\
		  ${ECHO} "#include <soundcard.h>";			\
		  ${ECHO} "#endif";					\
		) > $${sys_soundcard_h};				\
	fi

.endif	# OSSAUDIO_BUILDLINK2_MK
