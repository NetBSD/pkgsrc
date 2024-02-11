# $NetBSD: buildlink3.mk,v 1.3 2024/02/11 18:58:02 vins Exp $

BUILDLINK_TREE+=	libbsd

.if !defined(LIBBSD_BUILDLINK3_MK)
LIBBSD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libbsd+=	libbsd>=0.11.6
BUILDLINK_ABI_DEPENDS.libbsd+=	libbsd>=0.11.8
BUILDLINK_PKGSRCDIR.libbsd?=	../../devel/libbsd

#BUILDLINK_INCDIRS.libbsd?=	include/bsd
BUILDLINK_CFLAGS.libbsd+=	-I${BUILDLINK_PREFIX.libbsd}/include/bsd -DLIBBSD_OVERLAY
BUILDLINK_LIBNAME.libbsd=	bsd
BUILDLINK_LDADD.libbsd=		${BUILDLINK_LIBNAME.libbsd:S/^/-l/:S/^-l$//}

.include "../../devel/libmd/buildlink3.mk"
BUILDLINK_LDADD.libbsd+=	${BUILDLINK_LDADD.libmd}
BUILDLINK_LDFLAGS.libbsd+=	${BUILDLINK_LDADD.libbsd}

.endif	# LIBBSD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libbsd
