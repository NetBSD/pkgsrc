# $NetBSD: Makefile,v 1.7 2018/07/28 14:40:47 brook Exp $

CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/combinat/
COMMENT=	Routines for combinatorics
LICENSE=	gnu-gpl-v2

R_PKGNAME=	combinat
R_PKGVER=	0.0-8

post-extract:
	echo 'exportPattern("^[^\\.]")' > ${WRKSRC}/NAMESPACE

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
