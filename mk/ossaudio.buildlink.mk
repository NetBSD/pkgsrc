# $NetBSD: ossaudio.buildlink.mk,v 1.6 2001/11/30 17:21:56 jlam Exp $
#
# This Makefile fragment is included by packages that use OSS audio.
#
# To use this Makefile fragment, simply:
#
# (1) Include this Makefile fragment in the package Makefile,
# (2) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (3) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(OSSAUDIO_BUILDLINK_MK)
OSSAUDIO_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"
.include "../../mk/bsd.prefs.mk"

.if ${_OPSYS_HAS_OSSAUDIO} == "yes"
BUILDLINK_PREFIX.ossaudio=	/usr
BUILDLINK_FILES.ossaudio=	lib/libossaudio.*

BUILDLINK_TARGETS.ossaudio=	ossaudio-buildlink
BUILDLINK_TARGETS.ossaudio+=	ossaudio-buildlink-soundcard-h
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.ossaudio}

LIBOSSAUDIO?=			-lossaudio
MAKE_ENV+=			LIBOSSAUDIO="${LIBOSSAUDIO}"

pre-configure: ${BUILDLINK_TARGETS.ossaudio}
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
.endif

.endif	# OSSAUDIO_BUILDLINK_MK
