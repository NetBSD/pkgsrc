# $NetBSD: Makefile,v 1.14 2005/05/22 20:08:25 jlam Exp $
#
# todo: set location of [md-]whois.conf and fix in man page too
# todo: build and install the po/ files and add to PLIST
# todo: add choice for mk/bsd.pkg.defaults.mk to define name prefix
# (defaults to "md-" to distinguish from other whois clients) and adjust PLIST

DISTNAME=	whois_${VERSION}
PKGNAME=	md-whois-${VERSION}
CATEGORIES=	net
MASTER_SITES=	http://ftp.debian.org/debian/pool/main/w/whois/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.linux.it/~md/software/
COMMENT=	Improved whois client

VERSION=	4.7.2

WRKSRC=		${WRKDIR}/whois-${VERSION}
USE_PERL5=	build
USE_TOOLS+=	gmake
INSTALLATION_DIRS+=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/whois ${PREFIX}/bin/md-whois
	${INSTALL_MAN} ${WRKSRC}/whois.1 ${PREFIX}/man/man1/md-whois.1

.include "../../mk/bsd.pkg.mk"
