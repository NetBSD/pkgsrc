# $NetBSD: Makefile,v 1.21 2008/11/19 14:35:34 taca Exp $
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

VERSION=	4.7.28

WRKSRC=		${WRKDIR}/whois-${VERSION}
USE_TOOLS+=	gmake perl

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1
PKG_DESTDIR_SUPPORT=	user-destdir

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/whois ${DESTDIR}${PREFIX}/bin/md-whois
	${INSTALL_MAN} ${WRKSRC}/whois.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/md-whois.1

.include "../../mk/bsd.pkg.mk"
