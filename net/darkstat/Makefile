# $NetBSD: Makefile,v 1.5 2007/06/11 15:23:12 obache Exp $
#

DISTNAME=		darkstat-3.0.619
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		http://dmr.ath.cx/net/darkstat/
DIST_SUBDIR=		darkstat
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://dmr.ath.cx/net/darkstat/
COMMENT=		Network statistics gatherer

BUILD_TARGET=		darkstat

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-chroot-dir=${PREFIX}/share/darkstat/chroot

BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=0.6.0

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/darkstat
	${INSTALL_DATA_DIR} ${PREFIX}/share/darkstat/chroot

.include "../../devel/zlib/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
