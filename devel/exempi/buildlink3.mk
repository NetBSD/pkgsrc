# $NetBSD: buildlink3.mk,v 1.3 2011/11/26 06:08:47 sbd Exp $

BUILDLINK_TREE+=	exempi

.if !defined(EXEMPI_BUILDLINK3_MK)
EXEMPI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.exempi+=	exempi>=1.99.9
BUILDLINK_ABI_DEPENDS.exempi?=	exempi>=2.1.1nb2
BUILDLINK_PKGSRCDIR.exempi?=	../../devel/exempi

.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.endif # EXEMPI_BUILDLINK3_MK

BUILDLINK_TREE+=	-exempi
