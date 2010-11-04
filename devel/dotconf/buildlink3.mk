# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/11/04 16:57:00 ahoka Exp $

BUILDLINK_TREE+=	dotconf

.if !defined(DOTCONF_BUILDLINK3_MK)
DOTCONF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dotconf+=	dotconf>=1.3
BUILDLINK_PKGSRCDIR.dotconf?=	../../devel/dotconf
.endif	# DOTCONF_BUILDLINK3_MK

BUILDLINK_TREE+=	-dotconf
