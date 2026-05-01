# $NetBSD: Makefile,v 1.9 2026/05/01 17:49:02 fox Exp $

DISTNAME=	btop-1.4.7
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=aristocratos/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aristocratos/btop
COMMENT=	Colorful TTY resource monitor
LICENSE=	apache-2.0

# gcc 10 support was removed from the code base.
# https://github.com/aristocratos/btop/pull/1106
GCC_REQD+=	14

TOOL_DEPENDS+=	lowdown-[0-9]*:../../textproc/lowdown

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

USE_CXX_FEATURES+=	c++20

INSTALLATION_DIRS=	${PKGMANDIR}/man1

CXXFLAGS+=	-DNDEBUG
MAKE_ENV+=	STRIP=true VERBOSE=true

SUBST_CLASSES+=		themes
SUBST_SED.themes+=	-e 's,/usr/local/share/btop/themes,${PREFIX}/share/btop/themes,'
SUBST_SED.themes+=	-e 's,/usr/.local/.share/btop/themes,${PREFIX}/share/btop/themes,'
SUBST_FILES.themes+=	src/btop_menu.cpp
SUBST_FILES.themes+=	src/btop.cpp
SUBST_STAGE.themes=	pre-configure
SUBST_MESSAGE.themes=	Fixing hardcoded paths to themes.

post-extract:
	# Fix permission issues.
	${CHMOD} -R go-w ${WRKSRC}

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
