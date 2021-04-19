# $NetBSD: buildlink3.mk,v 1.3 2021/04/19 10:14:56 nia Exp $

BUILDLINK_TREE+=	allegro5

.if !defined(ALLEGRO5_BUILDLINK3_MK)
ALLEGRO5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.allegro5+=	allegro5>=5.2.6.0
BUILDLINK_PKGSRCDIR.allegro5?=		../../devel/allegro5

pkgbase:= allegro5

.include "../../mk/pkg-build-options.mk"

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} != "Darwin"
.  include "../../graphics/MesaLib/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.allegro5:Mx11}
.  include "../../x11/libX11/buildlink3.mk"
.endif
.endif	# ALLEGRO5_BUILDLINK3_MK

BUILDLINK_TREE+=	-allegro5
