# $NetBSD: Makefile,v 1.6 2013/06/13 20:11:05 fhajny Exp $
#

DISTNAME=	node-v0.10.11
CATEGORIES=	devel
MASTER_SITES=	http://nodejs.org/dist/${DISTNAME:S/node-//}/
PKGNAME=	${DISTNAME:S/-v/js-/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nodejs.org/
COMMENT=	V8 JavaScript for clients and servers
LICENSE=	mit

HAS_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

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
REPLACE_PYTHON+=	tools/gyp/pylib/gyp/sun_tool.py
REPLACE_PYTHON+=	tools/node-waf
REPLACE_PYTHON+=	tools/waf-light
REPLACE_PYTHON+=	tools/wafadmin/*.py
REPLACE_PYTHON+=	tools/wafadmin/Tools/*.py

CHECK_INTERPRETER_SKIP+=	lib/node_modules/npm/*

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD"
. include "../../devel/libexecinfo/buildlink3.mk"
.endif
.if ${OPSYS} == "NetBSD"
BUILD_DEPENDS+=	lockf-[0-9]*:../../sysutils/lockf
.endif
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
