# $NetBSD: buildlink3.mk,v 1.5 2004/10/31 10:40:50 recht Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXML2_BUILDLINK3_MK:=	${LIBXML2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libxml2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibxml2}
BUILDLINK_PACKAGES+=	libxml2

.if !empty(LIBXML2_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libxml2+=	libxml2>=2.6.2
BUILDLINK_RECOMMENDED.libxml2+=	libxml2>=2.6.15
BUILDLINK_PKGSRCDIR.libxml2?=	../../textproc/libxml2
.endif	# LIBXML2_BUILDLINK3_MK

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
