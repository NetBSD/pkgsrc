# $NetBSD: buildlink3.mk,v 1.1 2013/07/02 12:03:24 rodent Exp $

BUILDLINK_TREE+=	tap-plugins

.if !defined(TAP_PLUGINS_BUILDLINK3_MK)
TAP_PLUGINS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tap-plugins+=	tap-plugins>=0.7.2
BUILDLINK_PKGSRCDIR.tap-plugins?=	../../audio/tap-plugins
.endif	# TAP_PLUGINS_BUILDLINK3_MK

BUILDLINK_TREE+=	-tap-plugins
