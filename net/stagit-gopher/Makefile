# $NetBSD: Makefile,v 1.1 2019/06/19 11:40:51 leot Exp $

DISTNAME=	stagit-gopher-0.9.2
CATEGORIES=	net
MASTER_SITES=	https://codemadness.org/releases/stagit-gopher/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://codemadness.org/git/stagit-gopher/file/README.html
COMMENT=	Static git page generator for gopher
LICENSE=	mit

USE_LANGUAGES=	c99

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-configure
SUBST_MESSAGE.makefile=	Adjust config.mk
SUBST_FILES.makefile=	config.mk
SUBST_SED.makefile+=	-e '/^CFLAGS/ s,-O2,,'
SUBST_SED.makefile+=	-e 's,^CFLAGS *= ,CFLAGS += ,'
SUBST_SED.makefile+=	-e 's,^LDFLAGS *= ,LDFLAGS += ,'

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=	GITINC=${PREFIX}/include
MAKE_FLAGS+=	GITLIB=${PREFIX}/lib

.include "../../devel/libgit2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
