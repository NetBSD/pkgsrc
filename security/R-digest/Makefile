# $NetBSD: Makefile,v 1.4 2018/02/28 18:12:31 minskim Exp $

CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dirk.eddelbuettel.com/code/digest.html
COMMENT=	Create cryptographic hash digests of R objects
LICENSE=	gnu-gpl-v2

R_PKGNAME=	digest
R_PKGVER=	0.6.15

BUILDLINK_API_DEPENDS.R+=	R>=2.4.1
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
