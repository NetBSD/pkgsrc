# $NetBSD: Makefile,v 1.3 2010/02/04 09:18:12 tnn Exp $

DISTNAME=	tuntap
PKGNAME=	solaris-tap-20070625
CATEGORIES=	net
MASTER_SITES=	http://www.whiteboard.ne.jp/~admin2/tuntap/source/tuntap/

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	http://www.whiteboard.ne.jp/~admin2/tuntap/
COMMENT=	Solaris kernel module for virtual Ethernet devices

PKG_DESTDIR_SUPPORT=	user-destdir

ONLY_FOR_PLATFORM=	SunOS-*-*
GNU_CONFIGURE=		yes

DIST_SUBDIR=	${PKGNAME_NOREV}
WRKSRC=		${WRKDIR}/tuntap

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS=	include/net lkm

do-install:
	${INSTALL_DATA} ${WRKSRC}/if_tun.h ${DESTDIR}${PREFIX}/include/net
.for f in tap tap.conf tun tun.conf
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/lkm
.endfor

.include "../../mk/bsd.pkg.mk"
