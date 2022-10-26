# $NetBSD: buildlink3.mk,v 1.26 2022/10/26 10:31:08 wiz Exp $

BUILDLINK_TREE+=	libnxml

.if !defined(LIBNXML_BUILDLINK3_MK)
LIBNXML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnxml+=	libnxml>=0.18.3
BUILDLINK_ABI_DEPENDS.libnxml+=	libnxml>=0.18.3nb26
BUILDLINK_PKGSRCDIR.libnxml?=	../../textproc/libnxml


.include "../../www/curl/buildlink3.mk"
.endif	# LIBNXML_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnxml
