# $NetBSD: buildlink3.mk,v 1.2 2022/02/26 03:58:10 pho Exp $

BUILDLINK_TREE+=	hs-turtle

.if !defined(HS_TURTLE_BUILDLINK3_MK)
HS_TURTLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-turtle+=	hs-turtle>=1.5.24
BUILDLINK_ABI_DEPENDS.hs-turtle+=	hs-turtle>=1.5.24nb1
BUILDLINK_PKGSRCDIR.hs-turtle?=		../../devel/hs-turtle

.include "../../textproc/hs-ansi-wl-pprint/buildlink3.mk"
.include "../../devel/hs-async/buildlink3.mk"
.include "../../time/hs-clock/buildlink3.mk"
.include "../../devel/hs-foldl/buildlink3.mk"
.include "../../sysutils/hs-hostname/buildlink3.mk"
.include "../../devel/hs-managed/buildlink3.mk"
.include "../../devel/hs-optional-args/buildlink3.mk"
.include "../../devel/hs-optparse-applicative/buildlink3.mk"
.include "../../devel/hs-streaming-commons/buildlink3.mk"
.include "../../sysutils/hs-system-fileio/buildlink3.mk"
.include "../../sysutils/hs-system-filepath/buildlink3.mk"
.include "../../sysutils/hs-temporary/buildlink3.mk"
.include "../../devel/hs-unix-compat/buildlink3.mk"
.endif	# HS_TURTLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-turtle
