# $NetBSD: buildlink3.mk,v 1.8 2022/01/13 08:02:29 adam Exp $

BUILDLINK_TREE+=	gcr

.if !defined(GCR_BUILDLINK3_MK)
GCR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcr+=	gcr>=3.18.0
BUILDLINK_ABI_DEPENDS.gcr+=	gcr>=3.38.0nb3
BUILDLINK_PKGSRCDIR.gcr?=	../../security/gcr

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.38
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/p11-kit/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# GCR_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcr
