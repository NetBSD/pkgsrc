# $NetBSD: buildlink3.mk,v 1.6 2022/02/26 12:33:45 pho Exp $

BUILDLINK_TREE+=	hs-fsnotify

.if !defined(HS_FSNOTIFY_BUILDLINK3_MK)
HS_FSNOTIFY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-fsnotify+=	hs-fsnotify>=0.3.0
BUILDLINK_ABI_DEPENDS.hs-fsnotify+=	hs-fsnotify>=0.3.0.1nb5
BUILDLINK_PKGSRCDIR.hs-fsnotify?=	../../devel/hs-fsnotify

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "Linux" || !empty(OPSYS:M*BSD)
.  include "../../devel/hs-hinotify/buildlink3.mk"
.  include "../../devel/hs-shelly/buildlink3.mk"
.endif

.include "../../devel/hs-async/buildlink3.mk"
.include "../../devel/hs-unix-compat/buildlink3.mk"
.endif	# HS_FSNOTIFY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-fsnotify
