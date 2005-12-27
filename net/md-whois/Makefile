# $NetBSD: Makefile,v 1.18 2005/12/27 21:24:26 reed Exp $
#
# todo: set location of [md-]whois.conf and fix in man page too
# todo: build and install the po/ files and add to PLIST
# todo: add choice for mk/defaults/mk.conf to define name prefix
# (defaults to "md-" to distinguish from other whois clients) and adjust PLIST

DISTNAME=	whois_${VERSION}
PKGNAME=	md-whois-${VERSION}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/w/whois/}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.linux.it/~md/software/
COMMENT=	Improved whois client

VERSION=	4.7.2

WRKSRC=		${WRKDIR}/whois-${VERSION}
USE_TOOLS+=	gmake perl

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/whois ${PREFIX}/bin/md-whois
	${INSTALL_MAN} ${WRKSRC}/whois.1 ${PREFIX}/${PKGMANDIR}/man1/md-whois.1

.include "../../mk/bsd.pkg.mk"
