# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 21:49:14 jlam Exp $

.if !defined(LIBLZO_BUILDLINK2_MK)
LIBLZO_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		liblzo
BUILDLINK_DEPENDS.liblzo?=	liblzo>=1.06
BUILDLINK_PKGSRCDIR.liblzo?=	../../archivers/liblzo

EVAL_PREFIX+=	BUILDLINK_PREFIX.liblzo=liblzo
BUILDLINK_PREFIX.liblzo_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.liblzo=		include/lzo1.h
BUILDLINK_FILES.liblzo+=	include/lzo16bit.h
BUILDLINK_FILES.liblzo+=	include/lzo1a.h
BUILDLINK_FILES.liblzo+=	include/lzo1b.h
BUILDLINK_FILES.liblzo+=	include/lzo1c.h
BUILDLINK_FILES.liblzo+=	include/lzo1f.h
BUILDLINK_FILES.liblzo+=	include/lzo1x.h
BUILDLINK_FILES.liblzo+=	include/lzo1y.h
BUILDLINK_FILES.liblzo+=	include/lzo1z.h
BUILDLINK_FILES.liblzo+=	include/lzo2a.h
BUILDLINK_FILES.liblzo+=	include/lzoconf.h
BUILDLINK_FILES.liblzo+=	include/lzoutil.h
BUILDLINK_FILES.liblzo+=	lib/liblzo.*

BUILDLINK_TARGETS+=		liblzo-buildlink

liblzo-buildlink: _BUILDLINK_USE

.endif	# LIBLZO_BUILDLINK2_MK
