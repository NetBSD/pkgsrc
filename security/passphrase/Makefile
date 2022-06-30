# $NetBSD: Makefile,v 1.8 2022/06/30 11:18:47 nia Exp $

DISTNAME=	1.2
PKGNAME=	passphrase-1.2
PKGREVISION=	1
DIST_SUBDIR=	passphrase
CATEGORIES=	security
MASTER_SITES=	https://git.sr.ht/~alva/passphrase/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.sr.ht/~alva/passphrase
COMMENT=	Zero-dependency passphrase generator
LICENSE=	mit

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

# \todo: There is currently an issue building this as a PIE, despite the
# buildsystem targeting it as a PIE.
MKPIE_SUPPORTED=	no
# RELRO checks fail for this package at the moment
RELRO_SUPPORTED=	no

.include "../../lang/python/pyversion.mk"
CONFLICTS+=	${PYPKGPREFIX}-pyutil-[0-9]*


SUBST_CLASSES+=		mandir
SUBST_STAGE.mandir=	pre-build
SUBST_MESSAGE.mandir=	replacing mandir location
SUBST_FILES.mandir=	build.zig
SUBST_SED.mandir+=	-e 's,"share" ++ sep ++ "man","${PKGMANDIR}",g'

.include "../../lang/zig/application.mk"
.include "../../mk/bsd.pkg.mk"
