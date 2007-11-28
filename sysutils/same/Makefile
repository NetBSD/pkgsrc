# $NetBSD: Makefile,v 1.4 2007/11/28 07:28:27 rillig Exp $

DISTNAME=	same-1.8
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.bitwizard.nl/same/

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	http://www.bitwizard.nl/
COMMENT=	Find identical files and link(2) them to save disk space

PKG_INSTALLATION_TYPES=	overwrite pkgviews

INSTALLATION_DIRS_FROM_PLIST=	yes
USE_BSD_MAKEFILE=	yes

post-extract:
	cd ${FILESDIR} && cp -f Makefile same.1 same.cat1 ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
