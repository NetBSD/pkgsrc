# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/04/15 11:49:02 wiz Exp $
#
# This Makefile fragment is included by packages that use gnet.
#
# This file was created automatically using createbuildlink 2.1.
#

.if !defined(GNET_BUILDLINK2_MK)
GNET_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gnet
BUILDLINK_DEPENDS.gnet?=		gnet>=1.1.7nb1
BUILDLINK_PKGSRCDIR.gnet?=		../../net/gnet1

EVAL_PREFIX+=	BUILDLINK_PREFIX.gnet=gnet
BUILDLINK_PREFIX.gnet_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gnet+=	include/gnet/conn.h
BUILDLINK_FILES.gnet+=	include/gnet/gnet.h
BUILDLINK_FILES.gnet+=	include/gnet/inetaddr.h
BUILDLINK_FILES.gnet+=	include/gnet/iochannel.h
BUILDLINK_FILES.gnet+=	include/gnet/mcast.h
BUILDLINK_FILES.gnet+=	include/gnet/md5.h
BUILDLINK_FILES.gnet+=	include/gnet/pack.h
BUILDLINK_FILES.gnet+=	include/gnet/server.h
BUILDLINK_FILES.gnet+=	include/gnet/sha.h
BUILDLINK_FILES.gnet+=	include/gnet/socks.h
BUILDLINK_FILES.gnet+=	include/gnet/tcp.h
BUILDLINK_FILES.gnet+=	include/gnet/udp.h
BUILDLINK_FILES.gnet+=	include/gnet/unix.h
BUILDLINK_FILES.gnet+=	include/gnet/url.h
BUILDLINK_FILES.gnet+=	lib/gnet/include/gnetconfig.h
BUILDLINK_FILES.gnet+=	lib/libgnet-1.1.*
BUILDLINK_FILES.gnet+=	lib/libgnet.*
BUILDLINK_FILES.gnet+=	lib/pkgconfig/gnet.pc

.include "../../devel/glib2/buildlink2.mk"

BUILDLINK_TARGETS+=	gnet-buildlink

gnet-buildlink: _BUILDLINK_USE

.endif	# GNET_BUILDLINK2_MK
