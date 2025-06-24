# $NetBSD: Makefile,v 1.4 2025/06/24 16:15:53 js Exp $

PKGNAME=	cryptopassphrase-1.0.1
DISTNAME=	v${PKGVERSION_NOREV}
CATEGORIES=	security
MASTER_SITES=	https://git.nil.im/js/CryptoPassphrase/archive/

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://git.nil.im/js/CryptoPassphrase
COMMENT=	Deterministic password generator based on scrypt
LICENSE=	isc

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
TOOL_DEPENDS+=	clang-[0-9]*:../../lang/clang
.endif

WRKSRC=			${WRKDIR}/cryptopassphrase
USE_LANGUAGES=		objc
PKGSRC_COMPILER=	clang	# Needs to be the same as devel/objfw

.include "../../devel/objfw/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
