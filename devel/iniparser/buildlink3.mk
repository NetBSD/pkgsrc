# $NetBSD: buildlink3.mk,v 1.1 2013/11/22 11:49:42 ryoon Exp $

BUILDLINK_TREE+=	iniparser

.if !defined(INIPARSER_BUILDLINK3_MK)
INIPARSER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.iniparser+=	iniparser>=3.1
BUILDLINK_PKGSRCDIR.iniparser?=	../../devel/iniparser
.endif	# INIPARSER_BUILDLINK3_MK

BUILDLINK_TREE+=	-iniparser
