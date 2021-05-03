# $NetBSD: buildlink3.mk,v 1.2 2021/05/03 19:00:59 pho Exp $

BUILDLINK_TREE+=	hs-fsnotify

.if !defined(HS_FSNOTIFY_BUILDLINK3_MK)
HS_FSNOTIFY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-fsnotify+=	hs-fsnotify>=0.3.0
BUILDLINK_ABI_DEPENDS.hs-fsnotify+=	hs-fsnotify>=0.3.0.1nb1
BUILDLINK_PKGSRCDIR.hs-fsnotify?=	../../devel/hs-fsnotify

.include "../../devel/hs-async/buildlink3.mk"
.include "../../devel/hs-unix-compat/buildlink3.mk"
.endif	# HS_FSNOTIFY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-fsnotify
