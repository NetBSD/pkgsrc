# $NetBSD: buildlink2.mk,v 1.3 2003/04/15 12:19:17 wiz Exp $
#
# This Makefile fragment is included by packages that use gnet.
#

.if !defined(GNET_BUILDLINK2_MK)
GNET_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gnet
BUILDLINK_DEPENDS.gnet?=		gnet>=2.0.0
BUILDLINK_PKGSRCDIR.gnet?=		../../net/gnet

EVAL_PREFIX+=	BUILDLINK_PREFIX.gnet=gnet
BUILDLINK_PREFIX.gnet_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gnet+=	include/gnet-2.0/*.h
BUILDLINK_FILES.gnet+=	lib/gnet-2.0/include/gnetconfig.h
BUILDLINK_FILES.gnet+=	lib/libgnet-2.0.*
BUILDLINK_FILES.gnet+=	lib/pkgconfig/gnet-2.0.pc

.include "../../devel/glib2/buildlink2.mk"

BUILDLINK_TARGETS+=	gnet-buildlink

gnet-buildlink: _BUILDLINK_USE

.endif	# GNET_BUILDLINK2_MK
