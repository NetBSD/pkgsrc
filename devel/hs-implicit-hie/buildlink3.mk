# $NetBSD: buildlink3.mk,v 1.8 2023/10/09 04:54:21 pho Exp $

BUILDLINK_TREE+=	hs-implicit-hie

.if !defined(HS_IMPLICIT_HIE_BUILDLINK3_MK)
HS_IMPLICIT_HIE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-implicit-hie+=	hs-implicit-hie>=0.1.4
BUILDLINK_ABI_DEPENDS.hs-implicit-hie+=	hs-implicit-hie>=0.1.4.0nb2
BUILDLINK_PKGSRCDIR.hs-implicit-hie?=	../../devel/hs-implicit-hie

.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../sysutils/hs-filepattern/buildlink3.mk"
.include "../../textproc/hs-yaml/buildlink3.mk"
.endif	# HS_IMPLICIT_HIE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-implicit-hie
