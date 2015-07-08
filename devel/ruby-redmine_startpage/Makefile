# $NetBSD: Makefile,v 1.2 2015/07/08 16:11:21 jperkin Exp $
#

GITHUB_TAG=	0.0.3
DISTNAME=	${GITHUB_TAG}
GITHUB_PROJECT=	redmine_startpage
PKGNAME=	${RUBY_PKGPREFIX}-${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=txinto/}
DIST_SUBDIR=	ruby-${GITHUB_PROJECT}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://gatatac.org/projects/redmine-startpage/wiki
COMMENT=	Redmine plugins to select any redmine subpage as start page
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/ruby-redmine-plugins/Makefile.common"

NO_CONFIGURE=	yes
NO_BUILD=	yes

STARTPAGE_PLUGIN_DIR=	${REDMINE_PLUGINDIR}/${GITHUB_PROJECT}

INSTALLATION_DIRS+=	${STARTPAGE_PLUGIN_DIR}/app/views/settings
INSTALLATION_DIRS+=	${STARTPAGE_PLUGIN_DIR}/config/locales
INSTALLATION_DIRS+=	${STARTPAGE_PLUGIN_DIR}/lib

do-install:
	${INSTALL_DATA}	${WRKSRC}/init.rb \
		${DESTDIR}${PREFIX}/${STARTPAGE_PLUGIN_DIR}
	${INSTALL_DATA}	${WRKSRC}/app/views/settings/* \
		${DESTDIR}${PREFIX}/${STARTPAGE_PLUGIN_DIR}/app/views/settings
	${INSTALL_DATA} ${WRKSRC}/config/locales/*.yml \
		 ${DESTDIR}${PREFIX}/${STARTPAGE_PLUGIN_DIR}/config/locales
	${INSTALL_DATA} ${WRKSRC}/lib/*.rb \
		 ${DESTDIR}${PREFIX}/${STARTPAGE_PLUGIN_DIR}/lib

.include "../../lang/ruby/rubyversion.mk"
.include "../../mk/bsd.pkg.mk"
