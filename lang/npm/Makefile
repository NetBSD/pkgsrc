# $NetBSD: Makefile,v 1.51 2022/06/28 11:34:14 wiz Exp $

DISTNAME=	npm-8.12.2
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=npm/}
GITHUB_PROJECT=	cli
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/npm/cli
COMMENT=	Package manager for JavaScript
LICENSE=	artistic-2.0

USE_TOOLS+=	bash gmake perl

MAKE_JOBS_SAFE=	no	# building man-pages

REPLACE_INTERPRETER+=	node
REPLACE.node.old=	.*node
REPLACE.node.new=	${PREFIX}/bin/node
REPLACE_FILES.node=	bin/npm-cli.js
REPLACE_FILES.node+=	bin/npx-cli.js

SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-configure
SUBST_FILES.python=	node_modules/node-gyp/lib/configure.js
SUBST_MESSAGE.python=	Fixing path to Python
SUBST_VARS.python=	PYTHONBIN

SUBST_CLASSES+=			man-directory
SUBST_STAGE.man-directory=	pre-configure
SUBST_FILES.man-directory=	node_modules/bin-links/lib/man-target.js
SUBST_MESSAGE.man-directory=	Changing installation to PREFIX/man
SUBST_VARS.man-directory=	DESTDIR PREFIX PKGMANDIR

CHECK_INTERPRETER_SKIP+=	lib/node_modules/npm/*

INSTALLATION_DIRS+=	lib/node_modules

.include "../../mk/bsd.prefs.mk"

do-install:
	${FIND} ${WRKSRC} -type f -name '*.orig' -delete
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${INSTALL_ENV} ${PREFIX}/bin/node \
		bin/npm-cli.js pack
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${INSTALL_ENV} ${PREFIX}/bin/node \
		bin/npm-cli.js install -g -f ${PKGNAME_NOREV}.tgz

.include "../../lang/nodejs/nodeversion.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
