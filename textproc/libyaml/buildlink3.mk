# $NetBSD: buildlink3.mk,v 1.2 2012/09/22 11:43:27 obache Exp $

BUILDLINK_TREE+=	libyaml

.if !defined(LIBYAML_BUILDLINK3_MK)
LIBYAML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libyaml+=	libyaml>=0.1.1
BUILDLINK_ABI_DEPENDS.libyaml+=	libyaml>=0.1.4
BUILDLINK_PKGSRCDIR.libyaml?=	../../textproc/libyaml
.endif	# LIBYAML_BUILDLINK3_MK

BUILDLINK_TREE+=	-libyaml
