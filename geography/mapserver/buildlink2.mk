# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/10/05 17:41:31 jschauma Exp $
#
# This Makefile fragment is included by packages that use mapserver.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(MAPSERVER_BUILDLINK2_MK)
MAPSERVER_BUILDLINK2_MK=		# defined

BUILDLINK_PACKAGES+=			mapserver
BUILDLINK_DEPENDS.mapserver?=		mapserver>=4.0
BUILDLINK_PKGSRCDIR.mapserver?=		../../geography/mapserver

EVAL_PREFIX+=	BUILDLINK_PREFIX.mapserver=mapserver
BUILDLINK_PREFIX.mapserver_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.mapserver+=		include/map.h
BUILDLINK_FILES.mapserver+=		lib/libmap.*

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/gd/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"

BUILDLINK_TARGETS+=			mapserver-buildlink

mapserver-buildlink: 			_BUILDLINK_USE

.endif	# MAPSERVER_BUILDLINK2_MK
