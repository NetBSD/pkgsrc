# $NetBSD: Makefile,v 1.2 2020/01/18 21:50:33 jperkin Exp $

R_PKGNAME=	openssl
R_PKGVER=	1.4.1
PKGREVISION=	1
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Toolkit for encryption, signatures and certificates based on OpenSSL
LICENSE=	mit

DEPENDS+=	R-askpass>=1.1:../../security/R-askpass

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
