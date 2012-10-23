# $NetBSD: Makefile,v 1.9 2012/10/23 19:51:22 asau Exp $

DISTNAME=	same-1.8
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.bitwizard.nl/same/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.bitwizard.nl/
COMMENT=	Find identical files and link(2) them to save disk space

PKG_INSTALLATION_TYPES=	overwrite pkgviews

AUTO_MKDIRS=			yes
USE_BSD_MAKEFILE=	yes

post-extract:
	cd ${FILESDIR} && cp -f Makefile same.1 same.cat1 ${WRKSRC}

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
