# $NetBSD: ossaudio.buildlink2.mk,v 1.1.2.2 2002/06/21 23:00:35 jlam Exp $

.if !defined(OSSAUDIO_BUILDLINK2_MK)
OSSAUDIO_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

.if ${_OPSYS_HAS_OSSAUDIO} == "yes"
BUILDLINK_PREFIX.ossaudio=	/usr
BUILDLINK_FILES.ossaudio=	lib/libossaudio.*

BUILDLINK_TARGETS+=		ossaudio-buildlink
BUILDLINK_TARGETS+=		ossaudio-buildlink-soundcard-h

LIBOSSAUDIO?=			-lossaudio
MAKE_ENV+=			LIBOSSAUDIO="${LIBOSSAUDIO}"

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

.endif	# OSSAUDIO_BUILDLINK2_MK
