# $NetBSD: buildlink3.mk,v 1.10 2025/04/21 16:04:30 wiz Exp $

BUILDLINK_TREE+=	libares

.if !defined(LIBARES_BUILDLINK3_MK)
LIBARES_BUILDLINK3_MK:=

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_API_DEPENDS.libares+=	libares>=1.1.1
BUILDLINK_PKGSRCDIR.libares?=	../../net/libares
BUILDLINK_DEPMETHOD.libares?=	build

.endif # LIBARES_BUILDLINK3_MK

BUILDLINK_TREE+=	-libares
