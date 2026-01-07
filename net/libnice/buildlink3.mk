# $NetBSD: buildlink3.mk,v 1.57 2026/01/07 08:48:21 wiz Exp $

BUILDLINK_TREE+=	libnice

.if !defined(LIBNICE_BUILDLINK3_MK)
LIBNICE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnice+=	libnice>=0.0.9
BUILDLINK_ABI_DEPENDS.libnice+=	libnice>=0.1.23nb1
BUILDLINK_PKGSRCDIR.libnice?=	../../net/libnice

.include "../../devel/glib2/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../net/gupnp-igd/buildlink3.mk"
.endif	# LIBNICE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnice
