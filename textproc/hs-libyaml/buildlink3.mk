# $NetBSD: buildlink3.mk,v 1.15 2025/03/05 03:40:00 pho Exp $

BUILDLINK_TREE+=	hs-libyaml

.if !defined(HS_LIBYAML_BUILDLINK3_MK)
HS_LIBYAML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-libyaml+=	hs-libyaml>=0.1.4
BUILDLINK_ABI_DEPENDS.hs-libyaml+=	hs-libyaml>=0.1.4nb3
BUILDLINK_PKGSRCDIR.hs-libyaml?=	../../textproc/hs-libyaml

.include "../../devel/hs-conduit/buildlink3.mk"
.include "../../devel/hs-resourcet/buildlink3.mk"
.include "../../textproc/libyaml/buildlink3.mk"
.endif	# HS_LIBYAML_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-libyaml
