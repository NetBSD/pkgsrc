# $NetBSD: Makefile,v 1.3 2018/05/04 09:40:02 adam Exp $

DISTNAME=	npm-6.0.0
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=npm/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	https://github.com/npm/npm/
COMMENT=	Package manager for JavaScript
LICENSE=	artistic-2.0

# Pre-fetch marked so that man pages can be built offline
MARKED=		marked-0.3.19
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} ${MARKED}.tar.gz
SITES.${MARKED}.tar.gz=	-https://github.com/markedjs/marked/archive/v${MARKED:S/marked-//}.tar.gz

USE_TOOLS+=	gmake perl

REPLACE_INTERPRETER+=	node
REPLACE.node.old=	.*node
REPLACE.node.new=	${PREFIX}/bin/node
REPLACE_FILES.node=	bin/npm-cli.js
REPLACE_FILES.node+=	bin/npx-cli.js

CHECK_INTERPRETER_SKIP+=lib/node_modules/npm/*

.include "../../mk/bsd.prefs.mk"

pre-build:
	cd ${WRKSRC} && node bin/npm-cli.js install ${WRKDIR}/${MARKED} --no-global --no-timing --no-save

do-install:
	${FIND} ${WRKSRC} -type f -name '*.orig' -delete
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} ${PREFIX}/bin/node \
		bin/npm-cli.js pack
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} ${PREFIX}/bin/node \
		bin/npm-cli.js install -g -f ${DISTNAME}.tgz
.if ${PKGMANDIR} != "share/man"
	${RM} -f -r ${DESTDIR}${PREFIX}/${PKGMANDIR}
	${MV} ${DESTDIR}${PREFIX}/share/man ${DESTDIR}${PREFIX}/${PKGMANDIR}
.endif

.include "../../lang/nodejs/nodeversion.mk"
.include "../../mk/bsd.pkg.mk"
