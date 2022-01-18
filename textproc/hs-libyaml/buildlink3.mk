# $NetBSD: buildlink3.mk,v 1.4 2022/01/18 02:48:27 pho Exp $

BUILDLINK_TREE+=	hs-libyaml

.if !defined(HS_LIBYAML_BUILDLINK3_MK)
HS_LIBYAML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-libyaml+=	hs-libyaml>=0.1.2
BUILDLINK_ABI_DEPENDS.hs-libyaml+=	hs-libyaml>=0.1.2nb2
BUILDLINK_PKGSRCDIR.hs-libyaml?=	../../textproc/hs-libyaml

.include "../../devel/hs-conduit/buildlink3.mk"
.include "../../devel/hs-resourcet/buildlink3.mk"
.include "../../textproc/libyaml/buildlink3.mk"
.endif	# HS_LIBYAML_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-libyaml
