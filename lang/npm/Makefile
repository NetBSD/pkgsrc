# $NetBSD: Makefile,v 1.23 2019/07/01 10:50:32 adam Exp $

DISTNAME=	cli-6.9.2
PKGNAME=	${DISTNAME:S/cli/npm/}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=npm/}
GITHUB_PROJECT=	cli
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	fhajny@NetBSD.org
HOMEPAGE=	https://github.com/npm/cli
COMMENT=	Package manager for JavaScript
LICENSE=	artistic-2.0

# Pre-fetch marked so that man pages can be built offline
MARKED=			marked-0.6.3
DISTFILES+=		${DISTNAME}${EXTRACT_SUFX} ${MARKED}.tar.gz
SITES.${MARKED}.tar.gz=	-https://github.com/markedjs/marked/archive/v${MARKED:S/marked-//}.tar.gz

DEPENDS+=	nodejs-[0-9]*:../../lang/nodejs

USE_TOOLS+=	gmake perl

PYTHON_VERSIONS_ACCEPTED=	27 # required by gyp scripts included

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
SUBST_FILES.man-directory=	node_modules/bin-links/index.js
SUBST_MESSAGE.man-directory=	Changing installation to PREFIX/man
SUBST_VARS.man-directory=	PKGMANDIR

CHECK_INTERPRETER_SKIP+=	lib/node_modules/npm/*

.include "../../mk/bsd.prefs.mk"

pre-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} node bin/npm-cli.js install \
		${WRKDIR}/${MARKED} --no-global --no-timing --no-save

do-install:
	${FIND} ${WRKSRC} -type f -name '*.orig' -delete
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${INSTALL_ENV} ${PREFIX}/bin/node \
		bin/npm-cli.js pack
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${INSTALL_ENV} ${PREFIX}/bin/node \
		bin/npm-cli.js install -g -f ${PKGNAME_NOREV}.tgz

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
