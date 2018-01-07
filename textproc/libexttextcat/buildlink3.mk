# $NetBSD: buildlink3.mk,v 1.2 2018/01/07 13:04:34 rillig Exp $

BUILDLINK_TREE+=	libexttextcat

.if !defined(LIBEXTTEXTCAT_BUILDLINK3_MK)
LIBEXTTEXTCAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libexttextcat+=	libexttextcat>=3.2
BUILDLINK_PKGSRCDIR.libexttextcat?=	../../textproc/libexttextcat
.endif

BUILDLINK_TREE+=	-libexttextcat
