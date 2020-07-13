# $NetBSD: buildlink3.mk,v 1.1 2020/07/13 18:37:22 wiz Exp $

BUILDLINK_TREE+=	tokyotyrant

.if !defined(TOKYOTYRANT_BUILDLINK3_MK)
TOKYOTYRANT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tokyotyrant+=	tokyotyrant>=1.1.41nb4
BUILDLINK_PKGSRCDIR.tokyotyrant?=	../../databases/tokyotyrant

.include "../../mk/bsd.fast.prefs.mk"

pkgbase := tokyotyrant
.include "../../mk/pkg-build-options.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../databases/tokyocabinet/buildlink3.mk"
.if ${PKG_BUILD_OPTIONS.tokyotyrant:Mlua}
.include "../../lang/lua/buildlink3.mk"
.endif

.endif	# TOKYOTYRANT_BUILDLINK3_MK

BUILDLINK_TREE+=	-tokyotyrant
