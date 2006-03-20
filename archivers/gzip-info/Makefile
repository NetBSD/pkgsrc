# $NetBSD: Makefile,v 1.22 2006/03/20 18:15:37 jlam Exp $

DISTNAME=	gzip-1.2.4a
PKGNAME=	gzip-info-1.2.4a
SVR4_PKGNAME=	gzipi
CATEGORIES=	archivers
MASTER_SITES=   ${MASTER_SITE_GNU:=gzip/}
EXTRACT_SUFX=	.shar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gzip/gzip.html
COMMENT=	Info format documentation for the GZIP utility

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_CONFIGURE=	yes
NO_BUILD=	yes
INFO_FILES=	# PLIST

INSTALLATION_DIRS=	${PKGINFODIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/gzip.info ${PREFIX}/${PKGINFODIR}

.include "../../mk/bsd.pkg.mk"
