# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/12/14 10:57:18 obache Exp $
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
CLUTTER_BUILDLINK3_MK:=	${CLUTTER_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	clutter
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nclutter}
BUILDLINK_PACKAGES+=	clutter
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}clutter

.if ${CLUTTER_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.clutter+=	clutter>=0.8.0
BUILDLINK_PKGSRCDIR.clutter?=	../../graphics/clutter

PRINT_PLIST_AWK+=	/^@dirrm include\/clutter-0.8$$/ \
				{ print "@comment in clutter: " $$0; next; }
.endif	# CLUTTER_BUILDLINK3_MK

pkgbase := clutter
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.clutter:Mx11)
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
