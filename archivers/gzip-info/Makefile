# $NetBSD: Makefile,v 1.13 2003/06/25 22:14:19 seb Exp $

DISTNAME=	gzip-1.2.4a
PKGNAME=	gzip-info-1.2.4a
SVR4_PKGNAME=	gzipi
CATEGORIES=	archivers
MASTER_SITES=   ${MASTER_SITE_GNU:=gzip/}
EXTRACT_SUFX=	.shar

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/gzip/gzip.html
COMMENT=	Info format documentation for the GZIP utility

USE_NEW_TEXINFO=	YES
INFO_FILES=	gzip.info

USE_BUILDLINK2=	yes

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/gzip.info ${PREFIX}/info

.include "../../mk/bsd.pkg.mk"
