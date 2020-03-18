# $NetBSD: buildlink3.mk,v 1.2 2020/03/18 01:26:30 nia Exp $

BUILDLINK_TREE+=	allegro5

.if !defined(ALLEGRO5_BUILDLINK3_MK)
ALLEGRO5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.allegro5+=	allegro5>=5.2.6.0
BUILDLINK_PKGSRCDIR.allegro5?=		../../devel/allegro5

pkgbase:= allegro5

.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.MesaLib:Mx11)
.  include "../../x11/libX11/buildlink3.mk"
.endif

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} != "Darwin"
.  include "../../graphics/MesaLib/buildlink3.mk"
.endif
.endif	# ALLEGRO5_BUILDLINK3_MK

BUILDLINK_TREE+=	-allegro5
