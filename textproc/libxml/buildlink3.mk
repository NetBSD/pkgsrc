# $NetBSD: buildlink3.mk,v 1.1 2004/02/15 12:27:10 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXML_BUILDLINK3_MK:=	${LIBXML_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libxml
.endif

.if !empty(LIBXML_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		libxml
BUILDLINK_DEPENDS.libxml+=	libxml>=1.8.11
BUILDLINK_PKGSRCDIR.libxml?=	../../textproc/libxml

.  include "../../devel/zlib/buildlink3.mk"
.endif # LIBXML_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
