# $NetBSD: Makefile,v 1.1 2024/08/10 23:51:48 js Exp $

DISTNAME=	cryptopassphrase-1.0
CATEGORIES=	security
MASTER_SITES=	https://fl.nil.im/cryptopassphrase/tarball/v${PKGVERSION_NOREV}/

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://fl.nil.im/cryptopassphrase
COMMENT=	Deterministic password generator based on scrypt
LICENSE=	isc

USE_LANGUAGES=		objc
PKGSRC_COMPILER=	clang	# Needs to be the same as devel/objfw

.include "../../devel/objfw/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
