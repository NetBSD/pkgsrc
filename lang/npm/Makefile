# $NetBSD: Makefile,v 1.1 2018/05/02 17:03:09 fhajny Exp $

DISTNAME=	npm-6.0.0
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=npm/}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	https://github.com/npm/npm/
COMMENT=	Package manager for JavaScript
LICENSE=	artistic-2.0

GITHUB_TAG=	v${PKGVERSION_NOREV}
USE_TOOLS+=	gmake perl
MAKE_JOBS_SAFE=	no

REPLACE_INTERPRETER+=		node
REPLACE.node.old=		.*node
REPLACE.node.new=		${PREFIX}/bin/node
REPLACE_FILES.node=		bin/npm-cli.js bin/npx-cli.js
CHECK_INTERPRETER_SKIP+=	lib/node_modules/npm/*

.include "../../mk/bsd.prefs.mk"

do-install:
	cd ${WRKSRC} && ${FIND} . -type f -name '*.orig' -exec ${RM} -f {} \;
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} ${PREFIX}/bin/node \
		bin/npm-cli.js pack
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} ${PREFIX}/bin/node \
		bin/npm-cli.js install -g -f ${DISTNAME}.tgz
.if ${PKGMANDIR} != "share/man"
	${MV} ${DESTDIR}${PREFIX}/share/man ${DESTDIR}${PREFIX}/${PKGMANDIR}
.endif

.include "../../lang/nodejs/nodeversion.mk"
.include "../../mk/bsd.pkg.mk"
