# $NetBSD: buildlink3.mk,v 1.10 2012/03/03 00:12:10 wiz Exp $

BUILDLINK_TREE+=	libassetml

.if !defined(LIBASSETML_BUILDLINK3_MK)
LIBASSETML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libassetml+=	libassetml>=1.2.1
BUILDLINK_ABI_DEPENDS.libassetml?=	libassetml>=1.2.1nb4
BUILDLINK_PKGSRCDIR.libassetml?=	../../multimedia/libassetml

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # LIBASSETML_BUILDLINK3_MK

BUILDLINK_TREE+=	-libassetml
