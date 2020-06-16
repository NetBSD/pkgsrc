# $NetBSD: Makefile,v 1.4 2020/06/16 11:46:57 nikita Exp $

DISTNAME=	1.0.0
PKGNAME=	passphrase-1.0.0
DIST_SUBDIR=	passphrase
CATEGORIES=	security
MASTER_SITES=	https://git.sr.ht/~alva/passphrase/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.sr.ht/~alva/passphrase
COMMENT=	Zero-dependency passphrase generator
LICENSE=	mit

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

.include "../../lang/python/pyversion.mk"
CONFLICTS+=	${PYPKGPREFIX}-pyutil-[0-9]*

SUBST_CLASSES+=		mandir
SUBST_STAGE.mandir=	pre-build
SUBST_MESSAGE.mandir=	replacing mandir location
SUBST_FILES.mandir=	build.zig
SUBST_SED.mandir+=	-e 's,"share" ++ sep ++ "man","${PKGMANDIR}",g'

.include "../../lang/zig/application.mk"
.include "../../mk/bsd.pkg.mk"
