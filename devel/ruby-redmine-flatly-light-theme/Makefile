# $NetBSD: Makefile,v 1.5 2020/03/15 16:23:57 taca Exp $
#

GITHUB_TAG=	v0.2.4
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${RUBY_PKGPREFIX}-redmine-flatly-light-theme-${DISTNAME:S/v//1}
GITHUB_PROJECT=	flatly_light_redmine
MASTER_SITES=	${MASTER_SITE_GITHUB:=Nitrino/}
DIST_SUBDIR=	ruby-redmine-flatly-light-theme

MAINTAINER=	pkgsrc-users@NetBSD.org
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
