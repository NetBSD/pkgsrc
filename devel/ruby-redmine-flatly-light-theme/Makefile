# $NetBSD: Makefile,v 1.3 2017/01/04 23:05:12 rodent Exp $
#

GITHUB_TAG=	v0.1.1
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${RUBY_PKGPREFIX}-redmine-flatly-light-theme-${DISTNAME:S/v//1}
GITHUB_PROJECT=	flatly_light_redmine
MASTER_SITES=	${MASTER_SITE_GITHUB:=Nitrino/}
DIST_SUBDIR=	ruby-redmine-flatly-light-theme

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/Nitrino/flatly_light_redmine
COMMENT=	Flatly light theme for Redmine
LICENSE=	mit

.include "../../meta-pkgs/ruby-redmine-themes/Makefile.common"

FLATLY_LIGHT_DIR=	${REDMINE_THEMEDIR}/flatly_light_redmine

INSTALLATION_DIRS+=	${FLATLY_LIGHT_DIR}/fonts ${FLATLY_LIGHT_DIR}/images
INSTALLATION_DIRS+=	${FLATLY_LIGHT_DIR}/javascripts
INSTALLATION_DIRS+=	${FLATLY_LIGHT_DIR}/stylesheets

do-install:
	for i in fonts javascripts stylesheets; do \
		${INSTALL_DATA} ${WRKSRC}/$$i/*.* \
			${DESTDIR}${PREFIX}/${FLATLY_LIGHT_DIR}/$$i; \
	done

.include "../../lang/ruby/rubyversion.mk"
.include "../../mk/bsd.pkg.mk"
