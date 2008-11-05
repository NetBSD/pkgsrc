# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/11/05 13:07:14 obache Exp $
#

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
JSON_GLIB_BUILDLINK3_MK:=	${JSON_GLIB_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	json-glib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Njson-glib}
BUILDLINK_PACKAGES+=	json-glib
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}json-glib

.if ${JSON_GLIB_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.json-glib+=	json-glib>=0.6.2
BUILDLINK_PKGSRCDIR.json-glib?=		../../textproc/json-glib
.endif	# JSON_GLIB_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
