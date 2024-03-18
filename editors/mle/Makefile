# $NetBSD: Makefile,v 1.1 2024/03/18 07:16:43 wiz Exp $

DISTNAME=	mle-1.7.2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=adsr/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	ktnb@posteo.net
HOMEPAGE=	https://github.com/adsr/mle/
COMMENT=	Termbox-based text editor
LICENSE=	apache-2.0

USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++

USE_CC_FEATURES+=	c99

MAKE_FLAGS+=	prefix=${PREFIX}

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

SUBST_CLASSES+=		lua
SUBST_MESSAGE.lua=	rewrite lua directory directives
SUBST_FILES.lua=	mle.h
SUBST_SED.lua=		-e 's,lua5.4/,lua-5.4/,g'
SUBST_STAGE.lua=	pre-build

SUBST_CLASSES+=		makefile
SUBST_MESSAGE.makefile=	remove -v flag from install(1) command
SUBST_FILES.makefile=	Makefile
SUBST_SED.makefile=	-e 's,install -v,install,g'
SUBST_STAGE.makefile=	pre-build

pre-install:
	${INSTALL_MAN} ${WRKSRC}/mle.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/pcre2/buildlink3.mk"
.include "../../lang/lua54/buildlink3.mk"
.include "../../devel/uthash/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
