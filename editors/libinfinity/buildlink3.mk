# $NetBSD: buildlink3.mk,v 1.8 2024/12/27 08:19:40 wiz Exp $

BUILDLINK_TREE+=	libinfinity

.if !defined(LIBINFINITY_BUILDLINK3_MK)
LIBINFINITY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libinfinity+=	libinfinity>=0.7.2
BUILDLINK_ABI_DEPENDS.libinfinity?=	libinfinity>=0.7.2nb8
BUILDLINK_PKGSRCDIR.libinfinity?=	../../editors/libinfinity

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/gsasl/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# LIBINFINITY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libinfinity
