# $NetBSD: buildlink3.mk,v 1.1 2014/05/21 01:20:44 joerg Exp $

BUILDLINK_TREE+=	soci

.if !defined(SOCI_BUILDLINK3_MK)
SOCI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.soci+=	soci>=3.2.2nb4
BUILDLINK_PKGSRCDIR.soci?=	../../databases/soci
.endif	# SOCI_BUILDLINK3_MK

BUILDLINK_TREE+=	-soci
