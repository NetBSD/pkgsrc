# $NetBSD: Makefile,v 1.3 2006/10/22 14:27:00 rillig Exp $

DISTNAME=	same-1.8
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.bitwizard.nl/same/

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	http://www.bitwizard.nl/
COMMENT=	Find identical files and link(2) them to save disk space

PKG_INSTALLATION_TYPES=	overwrite pkgviews

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
MAKE_ENV+=		${BSD_MAKE_ENV}

post-extract:
	cd ${FILESDIR} && cp -f Makefile same.1 ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
