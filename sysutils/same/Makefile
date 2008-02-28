# $NetBSD: Makefile,v 1.5 2008/02/28 11:58:49 rillig Exp $

DISTNAME=	same-1.8
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.bitwizard.nl/same/

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	http://www.bitwizard.nl/
COMMENT=	Find identical files and link(2) them to save disk space

PKG_INSTALLATION_TYPES=	overwrite pkgviews

AUTO_MKDIRS=			yes
USE_BSD_MAKEFILE=	yes

post-extract:
	cd ${FILESDIR} && cp -f Makefile same.1 same.cat1 ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
