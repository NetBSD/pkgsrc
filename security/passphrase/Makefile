# $NetBSD: Makefile,v 1.12 2024/04/24 20:27:39 nikita Exp $

DISTNAME=	1.8
PKGNAME=	passphrase-1.8
DIST_SUBDIR=	passphrase
CATEGORIES=	security
MASTER_SITES=	https://git.sr.ht/~alva/passphrase/archive/

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://git.sr.ht/~alva/passphrase
COMMENT=	Zero-dependency passphrase generator
LICENSE=	mit

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

.if ${MKDEBUG:Uyes:M[yY][eE][sS]} && ${INSTALL_UNSTRIPPED:Uyes:tl} == yes
ZIGBUILDARGS+=		-Dstrip=true
.endif

CONFLICTS+=	py[0-9]*-pyutil-[0-9]*

SUBST_CLASSES+=		mandir
SUBST_STAGE.mandir=	pre-build
SUBST_MESSAGE.mandir=	replacing mandir location
SUBST_FILES.mandir=	build.zig
SUBST_SED.mandir+=	-e 's|"share",||g'

.include "../../lang/zig/application.mk"
.include "../../mk/bsd.pkg.mk"
