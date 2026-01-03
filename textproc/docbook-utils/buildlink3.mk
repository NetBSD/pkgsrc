# $NetBSD: buildlink3.mk,v 1.1 2026/01/03 18:05:45 bsiegert Exp $

BUILDLINK_TREE+=	docbook-utils

.if !defined(DOCBOOK_UTILS_BUILDLINK3_MK)
DOCBOOK_UTILS_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.docbook-utils?=	build

BUILDLINK_API_DEPENDS.docbook-utils+=	docbook-utils>=0.6.15
BUILDLINK_PKGSRCDIR.docbook-utils?=	../../textproc/docbook-utils

.include "../../textproc/opensp/buildlink3.mk"
.endif	# DOCBOOK_UTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-docbook-utils
