# $NetBSD: buildlink3.mk,v 1.2 2008/09/06 20:54:33 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
TOTEM_PL_PARSER_BUILDLINK3_MK:=	${TOTEM_PL_PARSER_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	totem-pl-parser
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ntotem-pl-parser}
BUILDLINK_PACKAGES+=	totem-pl-parser
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}totem-pl-parser

.if ${TOTEM_PL_PARSER_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.totem-pl-parser+=	totem-pl-parser>=2.22.1
BUILDLINK_ABI_DEPENDS.totem-pl-parser?=	totem-pl-parser>=2.22.3nb1
BUILDLINK_PKGSRCDIR.totem-pl-parser?=	../../multimedia/totem-pl-parser
.endif	# TOTEM_PL_PARSER_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../mail/evolution-data-server/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
