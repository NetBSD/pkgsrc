# $NetBSD: Makefile,v 1.23 2014/05/03 15:57:17 fhajny Exp $

DISTNAME=	node-v0.10.28
CATEGORIES=	devel
MASTER_SITES=	http://nodejs.org/dist/${DISTNAME:S/node-//}/
PKGNAME=	${DISTNAME:S/-v/js-/}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://nodejs.org/
COMMENT=	V8 JavaScript for clients and servers
LICENSE=	mit

HAS_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

PYTHON_VERSIONS_INCOMPATIBLE=	33 # not yet ported as of 0.10.24

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

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

.if ${OPSYS} == "NetBSD"
CONFIGURE_ENV+=		GYP_DEFINES="OS=netbsd"
MAKE_ENV+=		GYP_DEFINES="OS=netbsd"
.endif

REPLACE_PYTHON+=	configure
REPLACE_PYTHON+=	tools/genv8constants.py
REPLACE_PYTHON+=	tools/gyp_node
REPLACE_PYTHON+=	tools/gyp/pylib/gyp/flock_tool.py
REPLACE_PYTHON+=	tools/gyp/pylib/gyp/sun_tool.py
REPLACE_PYTHON+=	tools/node-waf
REPLACE_PYTHON+=	tools/waf-light
REPLACE_PYTHON+=	tools/wafadmin/*.py
REPLACE_PYTHON+=	tools/wafadmin/Tools/*.py

CHECK_INTERPRETER_SKIP+=	lib/node_modules/npm/*

.if ${OPSYS} == "NetBSD"
BUILD_DEPENDS+=	lockf-[0-9]*:../../sysutils/lockf
.endif

pre-install:
	${FIND} ${WRKSRC}/deps/npm -name '*.orig' | ${XARGS} ${RM} -f
	${CHMOD} -R g-w ${WRKSRC}

.if ${OPSYS} != "Darwin"
.include "../../devel/libexecinfo/buildlink3.mk"
.endif
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
