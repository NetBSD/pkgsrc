# $NetBSD: buildlink3.mk,v 1.16 2009/03/16 23:17:14 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXML2_BUILDLINK3_MK:=	${LIBXML2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libxml2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibxml2}
BUILDLINK_PACKAGES+=	libxml2
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libxml2

.if !empty(LIBXML2_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libxml2+=	libxml2>=2.6.2
BUILDLINK_ABI_DEPENDS.libxml2+=	libxml2>=2.6.23nb1
BUILDLINK_PKGSRCDIR.libxml2?=	../../textproc/libxml2

BUILDLINK_FILES.libxml2+=	bin/xml2-config

USE_FEATURES+=		glob
.endif	# LIBXML2_BUILDLINK3_MK

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
