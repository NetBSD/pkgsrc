# $NetBSD: buildlink2.mk,v 1.7 2002/11/25 07:01:05 jlam Exp $

.if !defined(OSS_BUILDLINK2_MK)
OSS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		oss
BUILDLINK_DEPENDS.oss?=		oss-[0-9]*
BUILDLINK_PKGSRCDIR.oss?=	../../audio/oss

EVAL_PREFIX+=	BUILDLINK_PREFIX.oss=oss
BUILDLINK_PREFIX.oss_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.oss+=	lib/oss/include/sys/awe_voice.h
BUILDLINK_FILES.oss+=	lib/oss/include/sys/dm.h
BUILDLINK_FILES.oss+=	lib/oss/include/sys/soundcard.h
BUILDLINK_FILES.oss+=	lib/oss/include/sys/ultrasound.h
BUILDLINK_FILES.oss+=	lib/oss/libOSSlib.*

_OSSLIBDIR=		${BUILDLINK_PREFIX.oss}/lib/oss
BUILDLINK_CPPFLAGS.oss=	-I${_OSSLIBDIR}/include

BUILDLINK_PREFIX.ossaudio=	${_OSSLIBDIR}
BUILDLINK_FILES.ossaudio=	include/sys/awe_voice.h
BUILDLINK_FILES.ossaudio+=	include/sys/dm.h
BUILDLINK_FILES.ossaudio+=	include/sys/soundcard.h
BUILDLINK_FILES.ossaudio+=	include/sys/ultrasound.h

# If we are using audio/oss, then we don't need the NetBSD OSS
# compatibility library.
#
BUILDLINK_TRANSFORM+=		S:-lossaudio:

BUILDLINK_TARGETS+=	oss-buildlink
BUILDLINK_TARGETS+=	oss-buildlink-soundcard-h

LIBOSSAUDIO=		# empty
DEVOSSAUDIO=		/dev/dsp
DEVOSSSOUND=		${DEVOSSAUDIO}

oss-buildlink: _BUILDLINK_USE

# Many source files mistakenly include both <sys/soundcard.h> and
# <soundcard.h>, which causes errors since the definitions in the OSS
# sys/soundcard.h conflict with the definitions in the system soundcard.h.
# We fix this by making <sys/soundcard.h> and <soundcard.h> point to the
# same file and rely on multiple inclusion protection to prevent conflicts.
#
oss-buildlink-soundcard-h:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	soundcard_h=${BUILDLINK_DIR}/include/soundcard.h;		\
	sys_soundcard_h=${BUILDLINK_PREFIX.ossaudio}/include/sys/soundcard.h; \
	if [ ! -f $${soundcard_h} -a -f $${sys_soundcard_h} ]; then	\
		${ECHO_BUILDLINK_MSG}					\
			"Linking $${sys_soundcard_h} to $${soundcard_h}."; \
		${LN} -s $${sys_soundcard_h} $${soundcard_h};		\
        fi;                                                             \

.endif	# OSS_BUILDLINK2_MK
