# $NetBSD: buildlink3.mk,v 1.5 2007/11/30 17:12:35 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GOFFICE0.5_BUILDLINK3_MK:=	${GOFFICE0.5_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	goffice0.5
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngoffice0.5}
BUILDLINK_PACKAGES+=	goffice0.5
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}goffice0.5

.if ${GOFFICE0.5_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.goffice0.5+=	goffice0.5>=0.5.3
BUILDLINK_PKGSRCDIR.goffice0.5?=	../../misc/goffice0.5
.endif	# GOFFICE0.5_BUILDLINK3_MK

#.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
#.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
