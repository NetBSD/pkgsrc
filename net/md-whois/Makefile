# $NetBSD: Makefile,v 1.24 2012/10/03 21:56:55 wiz Exp $
#
# todo: set location of [md-]whois.conf and fix in man page too
# todo: build and install the po/ files and add to PLIST
# todo: add choice for mk/defaults/mk.conf to define name prefix
# (defaults to "md-" to distinguish from other whois clients) and adjust PLIST

DISTNAME=	whois_${VERSION}
PKGNAME=	md-whois-${VERSION}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/w/whois/}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.linux.it/~md/software/
COMMENT=	Improved whois client

VERSION=	5.0.11

WRKSRC=		${WRKDIR}/whois-${VERSION}
USE_TOOLS+=	gmake perl

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "NetBSD" && !empty(OS_VERSION:M4.*))
MAKE_ENV+=	NEED_OPTARG=YES
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/whois ${DESTDIR}${PREFIX}/bin/md-whois
	${INSTALL_MAN} ${WRKSRC}/whois.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/md-whois.1

.include "../../mk/bsd.pkg.mk"
