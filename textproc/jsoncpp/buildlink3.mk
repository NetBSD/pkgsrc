# $NetBSD: buildlink3.mk,v 1.1 2014/04/18 22:26:08 wiz Exp $

BUILDLINK_TREE+=	jsoncpp

.if !defined(JSONCPP_BUILDLINK3_MK)
JSONCPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jsoncpp+=	jsoncpp>=0.6.0rc2svn276
BUILDLINK_PKGSRCDIR.jsoncpp?=	../../textproc/jsoncpp
BUILDLINK_DEPMETHOD.jsoncpp?=	build
.endif	# JSONCPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-jsoncpp
