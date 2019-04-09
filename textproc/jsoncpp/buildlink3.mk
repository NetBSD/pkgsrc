# $NetBSD: buildlink3.mk,v 1.3 2019/04/09 07:08:18 wiz Exp $

BUILDLINK_TREE+=	jsoncpp

.if !defined(JSONCPP_BUILDLINK3_MK)
JSONCPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jsoncpp+=	jsoncpp>=1.8.4nb1
BUILDLINK_PKGSRCDIR.jsoncpp?=	../../textproc/jsoncpp
.endif	# JSONCPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-jsoncpp
