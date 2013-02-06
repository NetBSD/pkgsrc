# $NetBSD: buildlink3.mk,v 1.6 2013/02/06 23:21:35 jperkin Exp $

BUILDLINK_TREE+=	libxenserver

.if !defined(LIBXENSERVER_BUILDLINK3_MK)
LIBXENSERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxenserver+=	libxenserver>=5.6.100
BUILDLINK_ABI_DEPENDS.libxenserver+=	libxenserver>=5.6.100nb4
BUILDLINK_PKGSRCDIR.libxenserver?=	../../devel/libxenserver

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif	# LIBXENSERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxenserver
