# $NetBSD: buildlink3.mk,v 1.1 2020/04/28 13:42:47 nikita Exp $

BUILDLINK_TREE+=	pbc

.if !defined(PBC_BUILDLINK3_MK)
PBC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pbc+=	pbc>=0.5.14
BUILDLINK_PKGSRCDIR.pbc?=	../../security/libpbc

pkgbase:= pbc
.include "../../mk/pkg-build-options.mk"

.include "../../devel/gmp/buildlink3.mk"
.endif # PBC_BUILDLINK3_MK

BUILDLINK_TREE+=	-pbc
