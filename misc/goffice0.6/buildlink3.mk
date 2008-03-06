# $NetBSD: buildlink3.mk,v 1.2 2008/03/06 14:53:52 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GOFFICE0.6_BUILDLINK3_MK:=	${GOFFICE0.6_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	goffice0.6
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngoffice0.6}
BUILDLINK_PACKAGES+=	goffice0.6
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}goffice0.6

.if ${GOFFICE0.6_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.goffice0.6+=	goffice0.6>=0.6.1
BUILDLINK_ABI_DEPENDS.goffice0.6?=	goffice0.6>=0.6.1nb1
BUILDLINK_PKGSRCDIR.goffice0.6?=	../../misc/goffice0.6
.endif	# GOFFICE0.6_BUILDLINK3_MK

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
