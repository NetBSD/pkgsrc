# $NetBSD: buildlink3.mk,v 1.4 2008/01/18 05:08:34 tnn Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GOFFICE02_BUILDLINK3_MK:=	${GOFFICE02_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	goffice02
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngoffice02}
BUILDLINK_PACKAGES+=	goffice02
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}goffice02

.if !empty(GOFFICE02_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.goffice02+=	goffice0.2>=0.2.2nb1
BUILDLINK_ABI_DEPENDS.goffice02?=	goffice0.2>=0.2.2nb5
BUILDLINK_PKGSRCDIR.goffice02?=	../../misc/goffice0.2
.endif	# GOFFICE02_BUILDLINK3_MK

.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
