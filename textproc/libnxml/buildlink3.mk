# $NetBSD: buildlink3.mk,v 1.14 2018/08/16 18:54:32 adam Exp $

BUILDLINK_TREE+=	libnxml

.if !defined(LIBNXML_BUILDLINK3_MK)
LIBNXML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnxml+=	libnxml>=0.18.3
BUILDLINK_ABI_DEPENDS.libnxml+=	libnxml>=0.18.3nb13
BUILDLINK_PKGSRCDIR.libnxml?=	../../textproc/libnxml


.include "../../www/curl/buildlink3.mk"
.endif	# LIBNXML_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnxml
