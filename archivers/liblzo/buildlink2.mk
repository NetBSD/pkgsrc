# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/05/11 02:08:52 jlam Exp $
#
# This Makefile fragment is included by packages that use liblzo.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.liblzo to the dependency pattern
#     for the version of liblzo desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(LIBLZO_BUILDLINK2_MK)
LIBLZO_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.liblzo?=	liblzo>=1.06
DEPENDS+=	${BUILDLINK_DEPENDS.liblzo}:../../archivers/liblzo

BUILDLINK_PREFIX.liblzo=	${LOCALBASE}
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
