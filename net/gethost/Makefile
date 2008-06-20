# $NetBSD: Makefile,v 1.9 2008/06/20 01:09:30 joerg Exp $

DISTNAME=	gethost-0.03
CATEGORIES=	net
MASTER_SITES=	http://www.reedmedia.net/software/gethost/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.reedmedia.net/software/gethost/
COMMENT=	Hostname and IP resolver for testing /etc/hosts and nsswitch.conf

PKG_INSTALLATION_TYPES= overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
BUILD_TARGET=	gethost

LIBS.SunOS=	-lnsl -lresolv -lsocket

do-build:
	cd ${WRKSRC} && env ${MAKE_ENV} cc -o gethost gethost.c ${CFLAGS} ${LDFLAGS} ${LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gethost ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gethost.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

PKG_OPTIONS_VAR=		PKG_OPTIONS.gethost
PKG_OPTIONS_REQUIRED_GROUPS=	inet6 # require inet6 capability
PKG_OPTIONS_GROUP.inet6=	inet6

.include "../../mk/bsd.options.mk"
.include "../../mk/bsd.pkg.mk"
