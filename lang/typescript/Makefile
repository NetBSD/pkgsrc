# $NetBSD: Makefile,v 1.1 2026/09/22 13:31:37 kikadf Exp $

DISTNAME=	typescript-6.0.3
CATEGORIES=	lang
EXTRACT_SUFX=	.tgz
MASTER_SITES=	https://registry.npmjs.org/typescript/-/

MAINTAINER=	kikadf@NetBSD.org
HOMEPAGE=	https://www.typescriptlang.org/
COMMENT=	Superset of JavaScript that compiles to clean JavaScript output
LICENSE=	apache-2.0

USE_TOOLS+=	pax
USE_LANGUAGES=	# none

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/package

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	lib/node_modules/typescript

REPLACE_NODEJS+=	bin/tsc
REPLACE_NODEJS+=	bin/tsserver

do-install:
	${INSTALL_DATA} ${WRKSRC}/package.json \
		${DESTDIR}${PREFIX}/lib/node_modules/typescript/
.for i in bin lib
	${RUN} cd ${WRKSRC} && \
		${FIND} ${i} -type f -print | \
		pax -rw -pmp ${DESTDIR}${PREFIX}/lib/node_modules/typescript/
.endfor
	${RUN} cd ${DESTDIR}${PREFIX}/bin && \
		${LN} -sf ${PREFIX}/lib/node_modules/typescript/bin/tsc  tsc
	${RUN} cd ${DESTDIR}${PREFIX}/bin && \
		${LN} -sf ${PREFIX}/lib/node_modules/typescript/bin/tsserver tsserver

.include "../../lang/nodejs/application.mk"
.include "../../lang/nodejs/nodeversion.mk"
.include "../../mk/bsd.pkg.mk"
