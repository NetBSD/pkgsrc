# $NetBSD: Makefile,v 1.5 2018/07/28 14:40:52 brook Exp $

CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dirk.eddelbuettel.com/code/digest.html
COMMENT=	Create cryptographic hash digests of R objects
LICENSE=	gnu-gpl-v2

R_PKGNAME=	digest
R_PKGVER=	0.6.15

BUILDLINK_API_DEPENDS.R+=	R>=2.4.1
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
