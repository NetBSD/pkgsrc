# $NetBSD: buildlink2.mk,v 1.2 2003/04/15 12:17:19 wiz Exp $
#
# This Makefile fragment is included by packages that use gnet1.
#
# This file was created automatically using createbuildlink 2.1.
#

.if !defined(GNET1_BUILDLINK2_MK)
GNET1_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gnet1
BUILDLINK_DEPENDS.gnet1?=		gnet1>=1.1.7nb1
BUILDLINK_PKGSRCDIR.gnet1?=		../../net/gnet1

EVAL_PREFIX+=	BUILDLINK_PREFIX.gnet1=gnet1
BUILDLINK_PREFIX.gnet1_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gnet1+=	include/gnet/conn.h
BUILDLINK_FILES.gnet1+=	include/gnet/gnet.h
BUILDLINK_FILES.gnet1+=	include/gnet/inetaddr.h
BUILDLINK_FILES.gnet1+=	include/gnet/iochannel.h
BUILDLINK_FILES.gnet1+=	include/gnet/mcast.h
BUILDLINK_FILES.gnet1+=	include/gnet/md5.h
BUILDLINK_FILES.gnet1+=	include/gnet/pack.h
BUILDLINK_FILES.gnet1+=	include/gnet/server.h
BUILDLINK_FILES.gnet1+=	include/gnet/sha.h
BUILDLINK_FILES.gnet1+=	include/gnet/socks.h
BUILDLINK_FILES.gnet1+=	include/gnet/tcp.h
BUILDLINK_FILES.gnet1+=	include/gnet/udp.h
BUILDLINK_FILES.gnet1+=	include/gnet/unix.h
BUILDLINK_FILES.gnet1+=	include/gnet/url.h
BUILDLINK_FILES.gnet1+=	lib/gnet/include/gnetconfig.h
BUILDLINK_FILES.gnet1+=	lib/libgnet-1.1.*
BUILDLINK_FILES.gnet1+=	lib/libgnet.*
BUILDLINK_FILES.gnet1+=	lib/pkgconfig/gnet.pc

.include "../../devel/glib2/buildlink2.mk"

BUILDLINK_TARGETS+=	gnet1-buildlink

gnet1-buildlink: _BUILDLINK_USE

.endif	# GNET1_BUILDLINK2_MK
