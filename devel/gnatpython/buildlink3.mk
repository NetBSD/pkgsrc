# $NetBSD: buildlink3.mk,v 1.2 2023/08/14 05:24:08 wiz Exp $

BUILDLINK_TREE+=	gnatpython

.if !defined(GNATPYTHON_BUILDLINK3_MK)
GNATPYTHON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnatpython+=	gnatpython>=20101122
BUILDLINK_ABI_DEPENDS.gnatpython?=	gnatpython>=20110912nb7
BUILDLINK_PKGSRCDIR.gnatpython?=	../../devel/gnatpython

.endif	# GNATPYTHON_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnatpython
