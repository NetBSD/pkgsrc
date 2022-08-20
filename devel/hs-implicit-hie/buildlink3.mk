# $NetBSD: buildlink3.mk,v 1.3 2022/08/20 08:08:16 wiz Exp $

BUILDLINK_TREE+=	hs-implicit-hie

.if !defined(HS_IMPLICIT_HIE_BUILDLINK3_MK)
HS_IMPLICIT_HIE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-implicit-hie+=	hs-implicit-hie>=0.1.2
BUILDLINK_ABI_DEPENDS.hs-implicit-hie+=	hs-implicit-hie>=0.1.2.6nb2
BUILDLINK_PKGSRCDIR.hs-implicit-hie?=	../../devel/hs-implicit-hie

.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../sysutils/hs-filepattern/buildlink3.mk"
.include "../../textproc/hs-yaml/buildlink3.mk"
.endif	# HS_IMPLICIT_HIE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-implicit-hie
