# $NetBSD: buildlink3.mk,v 1.7 2023/01/26 15:08:26 pho Exp $

BUILDLINK_TREE+=	hs-fsnotify

.if !defined(HS_FSNOTIFY_BUILDLINK3_MK)
HS_FSNOTIFY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-fsnotify+=	hs-fsnotify>=0.4.1
BUILDLINK_ABI_DEPENDS.hs-fsnotify+=	hs-fsnotify>=0.4.1.0
BUILDLINK_PKGSRCDIR.hs-fsnotify?=	../../devel/hs-fsnotify

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "Linux" || ${OPSYS:M*BSD}
.  include "../../devel/hs-hinotify/buildlink3.mk"
.  include "../../devel/hs-shelly/buildlink3.mk"
.endif

.include "../../devel/hs-async/buildlink3.mk"
.include "../../devel/hs-monad-control/buildlink3.mk"
.include "../../devel/hs-safe-exceptions/buildlink3.mk"
.include "../../devel/hs-unix-compat/buildlink3.mk"
.endif	# HS_FSNOTIFY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-fsnotify
