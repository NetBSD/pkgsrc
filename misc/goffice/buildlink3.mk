# $NetBSD: buildlink3.mk,v 1.11 2007/05/05 00:33:43 wiz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GOFFICE_BUILDLINK3_MK:=	${GOFFICE_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	goffice
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngoffice}
BUILDLINK_PACKAGES+=	goffice
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}goffice

.if ${GOFFICE_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.goffice+=	goffice>=0.4.0
BUILDLINK_PKGSRCDIR.goffice?=	../../misc/goffice
.endif	# GOFFICE_BUILDLINK3_MK

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
