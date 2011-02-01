# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/02/01 20:44:47 drochner Exp $

BUILDLINK_TREE+=	gnatpython

.if !defined(GNATPYTHON_BUILDLINK3_MK)
GNATPYTHON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnatpython+=	gnatpython>=20101122
BUILDLINK_PKGSRCDIR.gnatpython?=	../../devel/gnatpython

.endif	# GNATPYTHON_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnatpython
