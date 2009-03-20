# $NetBSD: buildlink3.mk,v 1.18 2009/03/20 19:25:18 joerg Exp $

BUILDLINK_TREE+=	libfwbuilder

.if !defined(LIBFWBUILDER_BUILDLINK3_MK)
LIBFWBUILDER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfwbuilder+=	libfwbuilder>=2.0.12
BUILDLINK_ABI_DEPENDS.libfwbuilder+=	libfwbuilder>=2.0.12
BUILDLINK_PKGSRCDIR.libfwbuilder?=	../../security/libfwbuilder

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.endif # LIBFWBUILDER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfwbuilder
