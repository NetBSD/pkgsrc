# $NetBSD: Makefile,v 1.12 2012/10/23 17:18:22 asau Exp $

DISTNAME=	gethost-0.03
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.reedmedia.net/software/gethost/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.reedmedia.net/software/gethost/
COMMENT=	Hostname and IP resolver for testing /etc/hosts and nsswitch.conf

CONFLICTS=	dnssec-tools-[0-9]*

PKG_INSTALLATION_TYPES= overwrite pkgviews

USE_FEATURES=		inet6

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
BUILD_TARGET=	gethost

LIBS.SunOS=	-lnsl -lresolv -lsocket

do-build:
	cd ${WRKSRC} && env ${MAKE_ENV} cc -o gethost gethost.c ${CFLAGS} ${LDFLAGS} ${LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gethost ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gethost.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
