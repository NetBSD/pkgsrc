# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:24:16 joerg Exp $

BUILDLINK_TREE+=	libcfg

.if !defined(LIBCFG_BUILDLINK3_MK)
LIBCFG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcfg+=	libcfg+>=0.6.2nb1
BUILDLINK_ABI_DEPENDS.libcfg+=	libcfg+>=0.6.2nb3
BUILDLINK_PKGSRCDIR.libcfg?=	../../devel/libcfg+
.endif # LIBCFG_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcfg
