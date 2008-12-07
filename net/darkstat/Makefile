# $NetBSD: Makefile,v 1.9 2008/12/07 11:16:50 obache Exp $
#

DISTNAME=		darkstat-3.0.712
CATEGORIES=		net
MASTER_SITES=		http://dmr.ath.cx/net/darkstat/
DIST_SUBDIR=		darkstat
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://dmr.ath.cx/net/darkstat/
COMMENT=		Network statistics gatherer

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=		darkstat

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-chroot-dir=${PREFIX}/share/darkstat/chroot

BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=0.6.0

RCD_SCRIPTS=		darkstat

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/darkstat
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/darkstat/chroot

.include "../../devel/zlib/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
