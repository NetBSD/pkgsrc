# $NetBSD: buildlink3.mk,v 1.4 2023/11/02 06:36:35 pho Exp $

BUILDLINK_TREE+=	hs-hinotify

.if !defined(HS_HINOTIFY_BUILDLINK3_MK)
HS_HINOTIFY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hinotify+=	hs-hinotify>=0.4.1
BUILDLINK_ABI_DEPENDS.hs-hinotify+=	hs-hinotify>=0.4.1nb3
BUILDLINK_PKGSRCDIR.hs-hinotify?=	../../devel/hs-hinotify

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} != "Linux"
.include "../../devel/libinotify/buildlink3.mk"
.endif

.include "../../devel/hs-async/buildlink3.mk"
.endif	# HS_HINOTIFY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hinotify
