# $NetBSD: Makefile,v 1.18 2004/07/02 21:06:35 minskim Exp $

DISTNAME=	gzip-1.2.4a
PKGNAME=	gzip-info-1.2.4a
SVR4_PKGNAME=	gzipi
CATEGORIES=	archivers
MASTER_SITES=   ${MASTER_SITE_GNU:=gzip/}
EXTRACT_SUFX=	.shar

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gzip/gzip.html
COMMENT=	Info format documentation for the GZIP utility

PKG_INSTALLATION_TYPES=	overwrite pkgviews

INFO_FILES=	gzip.info

USE_BUILDLINK3=	yes

NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	${INFO_DIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/gzip.info ${PREFIX}/${INFO_DIR}

.include "../../mk/bsd.pkg.mk"
