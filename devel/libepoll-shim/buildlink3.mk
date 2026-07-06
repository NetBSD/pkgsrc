# $NetBSD: buildlink3.mk,v 1.3 2026/07/06 18:26:17 bsiegert Exp $

BUILDLINK_TREE+=	libepoll-shim

.if !defined(LIBEPOLL_SHIM_BUILDLINK3_MK)
LIBEPOLL_SHIM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libepoll-shim+=	libepoll-shim>=0.0.20210418
BUILDLINK_PKGSRCDIR.libepoll-shim?=	../../devel/libepoll-shim

.include "../../mk/bsd.fast.prefs.mk"

CHECK_BUILTIN.libepoll-shim:=	yes
.include "../../devel/libepoll-shim/builtin.mk"
CHECK_BUILTIN.libepoll-shim:=	no

.endif	# LIBEPOLL_SHIM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libepoll-shim
