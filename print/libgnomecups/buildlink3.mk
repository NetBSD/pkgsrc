# $NetBSD: buildlink3.mk,v 1.22 2012/09/15 10:06:11 obache Exp $

BUILDLINK_TREE+=	libgnomecups

.if !defined(LIBGNOMECUPS_BUILDLINK3_MK)
LIBGNOMECUPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgnomecups+=	libgnomecups>=0.2.0
BUILDLINK_ABI_DEPENDS.libgnomecups+=	libgnomecups>=0.2.3nb10
BUILDLINK_PKGSRCDIR.libgnomecups?=	../../print/libgnomecups

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../print/cups/buildlink3.mk"
.endif # LIBGNOMECUPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgnomecups
