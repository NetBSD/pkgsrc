# $NetBSD: buildlink2.mk,v 1.2 2002/10/03 08:04:28 jlam Exp $

.if !defined(OSS_BUILDLINK2_MK)
OSS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		oss
BUILDLINK_DEPENDS.oss?=		oss>=3.97d
BUILDLINK_PKGSRCDIR.oss?=	../../audio/oss

EVAL_PREFIX+=	BUILDLINK_PREFIX.oss=oss
BUILDLINK_PREFIX.oss_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.oss+=	lib/oss/include/sys/awe_voice.h
BUILDLINK_FILES.oss+=	lib/oss/include/sys/dm.h
BUILDLINK_FILES.oss+=	lib/oss/include/sys/soundcard.h
BUILDLINK_FILES.oss+=	lib/oss/include/sys/ultrasound.h
BUILDLINK_FILES.oss+=	lib/oss/libOSSlib.*

BUILDLINK_CPPFLAGS.oss=	-I${BUILDLINK_PREFIX.oss}/lib/oss/include
BUILDLINK_LDFLAGS.oss=	-L${BUILDLINK_PREFIX.oss}/lib/oss		\
			-Wl,-R${BUILDLINK_PREFIX.oss}/lib/oss

BUILDLINK_PREFIX.ossaudio=	${BUILDLINK_PREFIX.oss}/lib/oss
BUILDLINK_FILES.ossaudio=	include/sys/awe_voice.h
BUILDLINK_FILES.ossaudio+=	include/sys/dm.h
BUILDLINK_FILES.ossaudio+=	include/sys/soundcard.h
BUILDLINK_FILES.ossaudio+=	include/sys/ultrasound.h

BUILDLINK_TARGETS+=	oss-buildlink

LIBOSSAUDIO=		# empty
DEVOSSAUDIO=		/dev/dsp
DEVOSSSOUND=		${DEVOSSAUDIO}

oss-buildlink: _BUILDLINK_USE

.endif	# OSS_BUILDLINK2_MK
