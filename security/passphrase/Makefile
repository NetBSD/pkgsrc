# $NetBSD: Makefile,v 1.1 2020/06/16 10:30:32 nikita Exp $

DISTNAME=	1.0.0
PKGNAME=	passphrase-1.0.0
DIST_SUBDIR=	passphrase
CATEGORIES=	security
MASTER_SITES=	https://git.sr.ht/~alva/passphrase/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.sr.ht/~alva/passphrase
COMMENT=	Zero-dependency passphrase generator
LICENSE=	mit

USE_LANGUAGES=	c

BUILD_DEPENDS+=	zig>=0.6:../../lang/zig

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

SUBST_CLASSES+=		mandir
SUBST_STAGE.mandir=	pre-build
SUBST_MESSAGE.mandir=	replacing mandir location
SUBST_FILES.mandir=	build.zig
SUBST_SED.mandir+=	-e 's,"share" ++ sep ++ "man","${PKGMANDIR}",g'

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} zig build -Drelease-fast

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} zig build install -Drelease-fast --prefix ${DESTDIR}${PREFIX}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} zig build test

.include "../../mk/bsd.pkg.mk"
