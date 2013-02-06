# $NetBSD: Makefile,v 1.14 2013/02/06 19:30:56 jperkin Exp $
#

DISTNAME=		darkstat-3.0.715
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		http://unix4lyfe.org/darkstat/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://unix4lyfe.org/darkstat/
COMMENT=		Network statistics gatherer
LICENSE=		gnu-gpl-v2

BUILD_TARGET=		darkstat

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-chroot-dir=${PREFIX}/share/darkstat/chroot

RCD_SCRIPTS=		darkstat

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/darkstat
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/darkstat/chroot

.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=0.6.0
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
