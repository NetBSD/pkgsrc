# $NetBSD: Makefile,v 1.21 2022/07/13 11:41:06 jperkin Exp $

DISTNAME=	yarn-v1.22.19
PKGREVISION=	1
PKGNAME=	${DISTNAME:S/-v/-/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=yarnpkg/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://yarnpkg.com/
COMMENT=	JavaScript package manager
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

DEPENDS+=	nodejs-[0-9]*:../../lang/nodejs

INSTALLATION_DIRS=	bin libexec/yarn/bin libexec/yarn/lib

REPLACE_NODEJS=	bin/yarn.js

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

.include "../../lang/nodejs/application.mk"
.include "../../mk/bsd.pkg.mk"
