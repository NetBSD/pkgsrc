# $NetBSD: Makefile,v 1.4 2024/05/30 20:17:34 yhardy Exp $

DISTNAME=	1.4.2
PKGNAME=	${LUA_PKGPREFIX}-fennel-1.4.2
CATEGORIES=	lang
MASTER_SITES=	https://git.sr.ht/~technomancy/fennel/archive/
DIST_SUBDIR=	fennel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fennel-lang.org/
COMMENT=	The Fennel programming language
LICENSE=	mit

USE_LANGUAGES=	c
USE_TOOLS+=	gmake
NO_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/fennel-${PKGVERSION_NOREV}

DEPENDS+=	${LUA_BASEDEPENDS}

BUILD_TARGET=	build

# We can't use lang/lua/application.mk's 'REPLACE_LUA' facility because that
# is evaluated at configure-time -- which won't work because the shebang
# statement we're trying to fix is written to our script afterwards, at
# *build* time.
#
# Therefore, use this modification we've made to the Makefile, where we pass
# in the LUA_INTERPRETER directly.
MAKE_FLAGS+=	LUA_INTERPRETER=${LUA_INTERPRETER}

INSTALL_MAKE_FLAGS+=	PREFIX=${PREFIX}
INSTALL_MAKE_FLAGS+=	MAN_DIR=${PREFIX}/${PKGMANDIR}

PLIST_SUBST+=	LUADOTVER=${_LUA_DOT_VERSION}
FILES_SUBST+=	LUADOTVER=${_LUA_DOT_VERSION}

post-install:
	# also manpage?
	${MV} ${DESTDIR}${PREFIX}/bin/fennel ${DESTDIR}${PREFIX}/bin/fennel-${_LUA_DOT_VERSION}

.include "../../lang/lua/application.mk"
.include "../../lang/lua/tool.mk"
.include "../../mk/alternatives.mk"
.include "../../mk/bsd.pkg.mk"
