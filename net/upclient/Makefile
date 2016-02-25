# $NetBSD: Makefile,v 1.30 2016/02/25 16:20:53 jperkin Exp $
#

DISTNAME=	upclient-4.2.1.23
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://uptimes.atomicvoid.net/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://uptimes.hostingwired.com/
COMMENT=	Keeps track of your server uptime, and compares it to other hosts

BUILD_TARGET.DragonFly=	dragonfly
BUILD_TARGET.SunOS=	solaris
BUILD_TARGET.*=		bsd

EGDIR=		${PREFIX}/share/examples/upclient
CONF_FILES=	${EGDIR}/upclient.conf ${PKG_SYSCONFDIR}/upclient.conf
CFLAGS+=	-DPKG_SYSCONFDIR="\"${PKG_SYSCONFDIR}\""

RCD_SCRIPTS=	upclient

BUILD_DIRS=	src

INSTALLATION_DIRS=	bin share/doc/upclient ${EGDIR}

pre-configure:
	${MV} ${WRKSRC}/scripts/upchk ${WRKSRC}/scripts/upchk.bak
	${SED} \
		-e 's|@PREFIX@|${PREFIX}|g' \
		>${WRKSRC}/scripts/upchk <${WRKSRC}/scripts/upchk.bak

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/upclient ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DESTDIR}${PREFIX}/share/doc/upclient
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/upclient
	${INSTALL_DATA} ${WRKSRC}/HISTORY ${DESTDIR}${PREFIX}/share/doc/upclient
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/upclient
	${INSTALL_DATA} ${WRKSRC}/FAQ ${DESTDIR}${PREFIX}/share/doc/upclient
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${PREFIX}/share/doc/upclient
	${INSTALL_DATA} ${WRKSRC}/conf/upclient.conf ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
