# $NetBSD: buildlink3.mk,v 1.1 2012/12/08 23:20:07 wiz Exp $

BUILDLINK_TREE+=	libgee0.8

.if !defined(LIBGEE0.8_BUILDLINK3_MK)
LIBGEE0.8_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgee0.8+=	libgee0.8>=0.8.2
BUILDLINK_PKGSRCDIR.libgee0.8?=	../../devel/libgee0.8

.include "../../devel/glib2/buildlink3.mk"
.endif	# LIBGEE0.8_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgee0.8
