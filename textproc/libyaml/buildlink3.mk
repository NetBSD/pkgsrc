# $NetBSD: buildlink3.mk,v 1.1 2009/08/09 09:32:34 wiz Exp $

BUILDLINK_TREE+=	libyaml

.if !defined(LIBYAML_BUILDLINK3_MK)
LIBYAML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libyaml+=	libyaml>=0.1.1
BUILDLINK_PKGSRCDIR.libyaml?=	../../textproc/libyaml
.endif	# LIBYAML_BUILDLINK3_MK

BUILDLINK_TREE+=	-libyaml
