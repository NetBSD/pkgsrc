# $NetBSD: buildlink3.mk,v 1.2 2004/03/05 19:25:09 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
DBXML_BUILDLINK3_MK:=	${DBXML_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	dbxml
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ndbxml}
BUILDLINK_PACKAGES+=	dbxml

.if !empty(DBXML_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.dbxml+=	dbxml>=1.2.0
BUILDLINK_PKGSRCDIR.dbxml?=	../../databases/dbxml

.include "../../databases/db4/buildlink3.mk"
.include "../../textproc/libpathan/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"

.endif	# DBXML_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
