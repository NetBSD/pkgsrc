# $NetBSD: Makefile,v 1.9.2.2 2002/06/21 23:04:45 jlam Exp $

DISTNAME=	gzip-1.2.4a
PKGNAME=	gzip-info-1.2.4a
SVR4_PKGNAME=	gzipi
CATEGORIES=	archivers
MASTER_SITES=   ${MASTER_SITE_GNU:=gzip/}
EXTRACT_SUFX=	.shar

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/gzip/gzip.html
COMMENT=	Info format documentation for the GZIP utility

INFO_FILES=	gzip.info

USE_BUILDLINK2=	yes

NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/gzip.info ${PREFIX}/info

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
