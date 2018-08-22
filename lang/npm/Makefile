# $NetBSD: Makefile,v 1.11 2018/08/22 09:45:21 wiz Exp $

DISTNAME=	cli-6.3.0
PKGNAME=	${DISTNAME:S/cli/npm/}
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=npm/}
GITHUB_PROJECT=	cli
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	https://github.com/npm/cli/
COMMENT=	Package manager for JavaScript
LICENSE=	artistic-2.0

# Pre-fetch marked so that man pages can be built offline
MARKED=			marked-0.4.0
DISTFILES+=		${DISTNAME}${EXTRACT_SUFX} ${MARKED}.tar.gz
SITES.${MARKED}.tar.gz=	-https://github.com/markedjs/marked/archive/${MARKED:S/marked-//}.tar.gz

DEPENDS+=	nodejs-[0-9]*:../../lang/nodejs

USE_TOOLS+=	gmake perl

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # required by gyp scripts included

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

CHECK_INTERPRETER_SKIP+=lib/node_modules/npm/*

.include "../../mk/bsd.prefs.mk"

pre-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} node bin/npm-cli.js install ${WRKDIR}/${MARKED} --no-global --no-timing --no-save

do-install:
	${FIND} ${WRKSRC} -type f -name '*.orig' -delete
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${INSTALL_ENV} ${PREFIX}/bin/node \
		bin/npm-cli.js pack
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${INSTALL_ENV} ${PREFIX}/bin/node \
		bin/npm-cli.js install -g -f ${PKGNAME}.tgz
.if ${PKGMANDIR} != "share/man"
	${RM} -f -r ${DESTDIR}${PREFIX}/${PKGMANDIR}
	${MV} ${DESTDIR}${PREFIX}/share/man ${DESTDIR}${PREFIX}/${PKGMANDIR}
.endif

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
