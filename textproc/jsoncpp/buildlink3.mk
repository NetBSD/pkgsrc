# $NetBSD: buildlink3.mk,v 1.2 2019/04/09 06:48:18 wiz Exp $

BUILDLINK_TREE+=	jsoncpp

.if !defined(JSONCPP_BUILDLINK3_MK)
JSONCPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jsoncpp+=	jsoncpp>=0.6.0rc2svn276
BUILDLINK_PKGSRCDIR.jsoncpp?=	../../textproc/jsoncpp
.endif	# JSONCPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-jsoncpp
