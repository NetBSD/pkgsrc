# $NetBSD: Makefile,v 1.41 2015/09/17 10:42:34 fhajny Exp $

DISTNAME=	node-v4.1.0
CATEGORIES=	devel
MASTER_SITES=	http://nodejs.org/dist/${DISTNAME:S/node-//}/
PKGNAME=	${DISTNAME:S/-v/js-/}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://nodejs.org/
COMMENT=	V8 JavaScript for clients and servers
LICENSE=	mit

HAS_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 0.10.24

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

GCC_REQD+=		4.8

SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-configure
SUBST_MESSAGE.python=	Fixing Python references
SUBST_FILES.python=	node.gyp deps/v8/tools/gyp/v8.gyp
SUBST_VARS.python=	PYTHONBIN

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_MESSAGE.man=	Fixing man path
SUBST_FILES.man=	tools/install.py
SUBST_VARS.man=		PKGMANDIR

CONFIG_SHELL=		${PYTHONBIN}
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--shared-zlib

.if ${OPSYS} == "NetBSD"
CONFIGURE_ENV+=		GYP_DEFINES="OS=netbsd"
MAKE_ENV+=		GYP_DEFINES="OS=netbsd"
.endif

REPLACE_PYTHON+=	configure
REPLACE_PYTHON+=	tools/genv8constants.py
REPLACE_PYTHON+=	tools/gyp/pylib/gyp/flock_tool.py

CHECK_INTERPRETER_SKIP+=	lib/node_modules/npm/*

.if ${OPSYS} == "NetBSD"
BUILD_DEPENDS+=	lockf-[0-9]*:../../sysutils/lockf
.endif

TEST_TARGET=		check

pre-install:
	${FIND} ${WRKSRC}/deps/npm -name '*.orig' | ${XARGS} ${RM} -f
	${CHMOD} -R g-w ${WRKSRC}

.if ${OPSYS} != "Darwin"
.include "../../devel/libexecinfo/buildlink3.mk"
.endif
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
