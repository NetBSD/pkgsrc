# $NetBSD: buildlink3.mk,v 1.1 2020/03/23 11:10:02 bsiegert Exp $

BUILDLINK_TREE+=	web2c

.if !defined(WEB2C_BUILDLINK3_MK)
WEB2C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.web2c+=	web2c>=2019nb5
BUILDLINK_PKGSRCDIR.web2c?=	../../print/web2c

.endif	# WEB2C_BUILDLINK3_MK

BUILDLINK_TREE+=	-web2c
