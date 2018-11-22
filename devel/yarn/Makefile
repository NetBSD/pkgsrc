# $NetBSD: Makefile,v 1.2 2018/06/04 10:10:22 jmcneill Exp $

DISTNAME=	yarn-v1.12.3
PKGNAME=	${DISTNAME:S/-v/-/}
CATEGORIES=	devel
MASTER_SITES=	https://yarnpkg.com/downloads/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://yarnpkg.com/
COMMENT=	JavaScript package manager
LICENSE=	2-clause-bsd

DEPENDS+=	nodejs-[0-9]*:../../lang/nodejs

USE_LANGUAGES=	# none

INSTALLATION_DIRS=	bin libexec/yarn/bin libexec/yarn/lib

REPLACE_INTERPRETER+=	nodejs
REPLACE.nodejs.old=	.*node
REPLACE.nodejs.new=	${PREFIX}/bin/node
REPLACE_FILES.nodejs=	bin/yarn.js

do-build:
	${SED} ${FILES_SUBST_SED} ${FILESDIR}/yarn.sh >${WRKSRC}/yarn.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/yarn.js			\
	    ${DESTDIR}${PREFIX}/libexec/yarn/bin/yarn.js
	${INSTALL_DATA} ${WRKSRC}/lib/*.js			\
	    ${DESTDIR}${PREFIX}/libexec/yarn/lib/
	${INSTALL_SCRIPT} ${WRKSRC}/yarn.sh			\
	    ${DESTDIR}${PREFIX}/bin/yarn
	${INSTALL_SCRIPT} ${WRKSRC}/yarn.sh			\
	    ${DESTDIR}${PREFIX}/bin/yarnpkg

.include "../../mk/bsd.pkg.mk"
