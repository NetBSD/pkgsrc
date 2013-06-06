# $NetBSD: buildlink3.mk,v 1.39 2013/06/06 12:53:42 wiz Exp $

BUILDLINK_TREE+=	libfwbuilder

.if !defined(LIBFWBUILDER_BUILDLINK3_MK)
LIBFWBUILDER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfwbuilder+=	libfwbuilder>=4.1.3
BUILDLINK_ABI_DEPENDS.libfwbuilder+=	libfwbuilder>=4.1.3nb16
BUILDLINK_PKGSRCDIR.libfwbuilder?=	../../security/libfwbuilder

.include "../../devel/zlib/buildlink3.mk"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.endif # LIBFWBUILDER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfwbuilder
