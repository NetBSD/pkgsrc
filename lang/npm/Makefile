# $NetBSD: Makefile,v 1.2 2018/05/03 21:09:17 fhajny Exp $

DISTNAME=	npm-6.0.0
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=npm/}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	https://github.com/npm/npm/
COMMENT=	Package manager for JavaScript
LICENSE=	artistic-2.0

# Pre-fetch marked so that man pages can be built offline
MARKED=		marked-0.3.19
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} ${MARKED}.tar.gz
SITES.${MARKED}.tar.gz=	-https://github.com/markedjs/marked/archive/v${MARKED:S/marked-//}.tar.gz

GITHUB_TAG=	v${PKGVERSION_NOREV}
USE_TOOLS+=	gmake perl
MAKE_JOBS_SAFE=	no

REPLACE_INTERPRETER+=		node
REPLACE.node.old=		.*node
REPLACE.node.new=		${PREFIX}/bin/node
REPLACE_FILES.node=		bin/npm-cli.js bin/npx-cli.js
CHECK_INTERPRETER_SKIP+=	lib/node_modules/npm/*

.include "../../mk/bsd.prefs.mk"

pre-build:
	cd ${WRKSRC} && node bin/npm-cli.js install ${WRKDIR}/${MARKED} --no-global --no-timing --no-save

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
