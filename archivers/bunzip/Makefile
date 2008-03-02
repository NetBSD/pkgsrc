# $NetBSD: Makefile,v 1.17 2008/03/02 03:48:36 jlam Exp $

DISTNAME=	bunzip021.c
PKGNAME=	bunzip-0.21
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.muraroa.demon.co.uk/
COMMENT=	Decompressor for bzip .bz files

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o bunzip ${DISTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bunzip ${DESTDIR}${PREFIX}/bin/bunzip

.include "../../mk/bsd.pkg.mk"
