# $NetBSD: Makefile,v 1.4 2017/01/04 23:05:13 rodent Exp $

GITHUB_TAG=	v1.1.0
DISTNAME=	${GITHUB_TAG}
GITHUB_PROJECT=	redmine-theme-gitmike
PKGNAME=	${RUBY_PKGPREFIX}-redmine-gitmike-theme-${DISTNAME:S/v//1}
MASTER_SITES=	${MASTER_SITE_GITHUB:=makotokw/}
DIST_SUBDIR=	ruby-redmine-gitmike-theme

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/makotokw/redmine-theme-gitmike
COMMENT=	Github-like theme for Redmine
LICENSE=	gnu-gpl-v3

.include "../../meta-pkgs/ruby-redmine-themes/Makefile.common"

GITMIKE_DIR=		${REDMINE_THEMEDIR}/gitmike

INSTALLATION_DIRS+=	${GITMIKE_DIR}/images ${GITMIKE_DIR}/sass
INSTALLATION_DIRS+=	${GITMIKE_DIR}/stylesheets

do-install:
	${INSTALL_DATA} ${WRKSRC}/gulpfile.js \
		${DESTDIR}${PREFIX}/${GITMIKE_DIR}
	${INSTALL_DATA} ${WRKSRC}/package.json \
		${DESTDIR}${PREFIX}/${GITMIKE_DIR}
	for i in images sass stylesheets; do \
		${INSTALL_DATA} ${WRKSRC}/$$i/* \
			${DESTDIR}${PREFIX}/${GITMIKE_DIR}/$$i; \
	done

.include "../../lang/ruby/rubyversion.mk"
.include "../../mk/bsd.pkg.mk"
