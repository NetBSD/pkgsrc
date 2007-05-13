# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/05/13 22:43:35 wiz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GNUCASH_BUILDLINK3_MK:=	${GNUCASH_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	gnucash
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnucash}
BUILDLINK_PACKAGES+=	gnucash
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gnucash

.if ${GNUCASH_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.gnucash+=	gnucash>=2.1.0
BUILDLINK_PKGSRCDIR.gnucash?=	../../finance/gnucash-current
.endif	# GNUCASH_BUILDLINK3_MK

#.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
#.include "../../devel/g-wrap/buildlink3.mk"
#.include "../../devel/libgsf/buildlink3.mk"
#.include "../../devel/libglade2/buildlink3.mk"
#.include "../../devel/libgnomeui/buildlink3.mk"
#.include "../../devel/pango/buildlink3.mk"
#.include "../../devel/popt/buildlink3.mk"
#.include "../../devel/zlib/buildlink3.mk"
#.include "../../finance/libofx/buildlink3.mk"
#.include "../../lang/guile/buildlink3.mk"
#.include "../../lang/perl5/buildlink3.mk"
#.include "../../misc/goffice0.2/buildlink3.mk"
#.include "../../print/libgnomeprint/buildlink3.mk"
#.include "../../print/libgnomeprintui/buildlink3.mk"
#.include "../../textproc/libxml2/buildlink3.mk"
#.include "../../www/gtkhtml38/buildlink3.mk"
#.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
