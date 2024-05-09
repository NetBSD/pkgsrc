# $NetBSD: buildlink3.mk,v 1.5 2024/05/09 01:31:59 pho Exp $

BUILDLINK_TREE+=	hs-hinotify

.if !defined(HS_HINOTIFY_BUILDLINK3_MK)
HS_HINOTIFY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hinotify+=	hs-hinotify>=0.4.1
BUILDLINK_ABI_DEPENDS.hs-hinotify+=	hs-hinotify>=0.4.1nb4
BUILDLINK_PKGSRCDIR.hs-hinotify?=	../../devel/hs-hinotify

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} != "Linux"
.include "../../devel/libinotify/buildlink3.mk"
.endif

.include "../../devel/hs-async/buildlink3.mk"
.endif	# HS_HINOTIFY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hinotify
