# $NetBSD: Makefile,v 1.7 2007/01/03 15:51:24 tv Exp $

DISTNAME=	gethost-0.03
CATEGORIES=	net
MASTER_SITES=	http://www.reedmedia.net/software/gethost/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.reedmedia.net/software/gethost/
COMMENT=	Hostname and IP resolver for testing /etc/hosts and nsswitch.conf

PKG_INSTALLATION_TYPES= overwrite pkgviews
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
BUILD_TARGET=	gethost

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gethost ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gethost.1 ${PREFIX}/${PKGMANDIR}/man1

PKG_OPTIONS_VAR=		PKG_OPTIONS.gethost
PKG_OPTIONS_REQUIRED_GROUPS=	inet6 # require inet6 capability
PKG_OPTIONS_GROUP.inet6=	inet6

.include "../../mk/bsd.options.mk"
.include "../../mk/bsd.pkg.mk"
