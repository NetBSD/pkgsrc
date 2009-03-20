# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:21 joerg Exp $

BUILDLINK_TREE+=	openvas-libnasl

.if !defined(OPENVAS_LIBNASL_BUILDLINK3_MK)
OPENVAS_LIBNASL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openvas-libnasl+=	openvas-libnasl>=2.0.0
BUILDLINK_PKGSRCDIR.openvas-libnasl?=	../../security/openvas-libnasl
.endif # OPENVAS_LIBNASL_BUILDLINK3_MK

BUILDLINK_TREE+=	-openvas-libnasl
