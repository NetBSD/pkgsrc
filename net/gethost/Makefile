# $NetBSD: Makefile,v 1.4 2004/04/16 20:26:10 reed Exp $

DISTNAME=	gethost-0.03
CATEGORIES=	net
MASTER_SITES=	http://www.reedmedia.net/software/gethost/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.reedmedia.net/software/gethost/
COMMENT=	Hostname and IP resolver for testing /etc/hosts and nsswitch.conf

PKG_INSTALLATION_TYPES= overwrite pkgviews
INSTALLATION_DIRS=	bin man/man1
ALL_TARGET=	gethost

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gethost ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gethost.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
