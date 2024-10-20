# $NetBSD: buildlink3.mk,v 1.3 2024/10/20 14:03:41 wiz Exp $

BUILDLINK_TREE+=	libinfinity

.if !defined(LIBINFINITY_BUILDLINK3_MK)
LIBINFINITY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libinfinity+=	libinfinity>=0.7.2
BUILDLINK_ABI_DEPENDS.libinfinity?=	libinfinity>=0.7.2nb3
BUILDLINK_PKGSRCDIR.libinfinity?=	../../editors/libinfinity

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/gsasl/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# LIBINFINITY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libinfinity
