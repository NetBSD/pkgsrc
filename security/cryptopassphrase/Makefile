# $NetBSD: Makefile,v 1.3 2024/12/18 08:34:06 wiz Exp $

DISTNAME=	cryptopassphrase-1.0.1
CATEGORIES=	security
MASTER_SITES=	https://fl.nil.im/cryptopassphrase/tarball/v${PKGVERSION_NOREV}/

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://fl.nil.im/cryptopassphrase
COMMENT=	Deterministic password generator based on scrypt
LICENSE=	isc

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
TOOL_DEPENDS+=	clang-[0-9]*:../../lang/clang
.endif

USE_LANGUAGES=		objc
PKGSRC_COMPILER=	clang	# Needs to be the same as devel/objfw

.include "../../devel/objfw/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
