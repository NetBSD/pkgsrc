# $NetBSD: buildlink3.mk,v 1.4 2024/03/05 19:44:36 vins Exp $

BUILDLINK_TREE+=	libbsd

.if !defined(LIBBSD_BUILDLINK3_MK)
LIBBSD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libbsd+=	libbsd>=0.12.1
BUILDLINK_ABI_DEPENDS.libbsd+=	libbsd>=0.12.1
BUILDLINK_PKGSRCDIR.libbsd?=	../../devel/libbsd

#BUILDLINK_INCDIRS.libbsd?=	include/bsd
BUILDLINK_CFLAGS.libbsd+=	-isystem${BUILDLINK_PREFIX.libbsd}/include/bsd -DLIBBSD_OVERLAY
BUILDLINK_LIBNAME.libbsd=	bsd
BUILDLINK_LDADD.libbsd=		${BUILDLINK_LIBNAME.libbsd:S/^/-l/:S/^-l$//}

.include "../../devel/libmd/buildlink3.mk"
BUILDLINK_LDADD.libbsd+=	${BUILDLINK_LDADD.libmd}
BUILDLINK_LDFLAGS.libbsd+=	${BUILDLINK_LDADD.libbsd}

.endif	# LIBBSD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libbsd
