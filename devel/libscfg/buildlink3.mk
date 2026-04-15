# $NetBSD: buildlink3.mk,v 1.1 2026/04/15 07:58:19 kikadf Exp $

BUILDLINK_TREE+=	libscfg

.if !defined(LIBSCFG_BUILDLINK3_MK)
LIBSCFG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libscfg+=	libscfg>=0.2.0
BUILDLINK_PKGSRCDIR.libscfg?=	../../devel/libscfg
.endif	# LIBSCFG_BUILDLINK3_MK

BUILDLINK_TREE+=	-libscfg
