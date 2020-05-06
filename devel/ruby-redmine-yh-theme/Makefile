# $NetBSD: Makefile,v 1.1 2020/05/06 14:01:03 taca Exp $

DISTNAME=	1.6
PKGNAME=	${RUBY_PKGPREFIX}-redmine-yh-theme-${DISTNAME}
MASTER_SITES=	${MASTER_SITE_GITHUB:=yenihayat/}
GITHUB_PROJECT=	redmine-theme-yh
DIST_SUBDIR=	ruby-redmine-yh-theme

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/yenihayat/redmine-theme-yh/
COMMENT=	Modern Redmine theme used in YeniHayat
LICENSE=	mit

.include "../../meta-pkgs/ruby-redmine-themes/Makefile.common"

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${DISTNAME}
YENIHAT_DIR=	${REDMINE_THEMEDIR}/yenihat

INSTALLATION_DIRS+=	${YENIHAT_DIR}/favicon ${YENIHAT_DIR}/images
INSTALLATION_DIRS+=	${YENIHAT_DIR}/javascripts ${YENIHAT_DIR}/stylesheets

do-install:
	for i in favicon images javascripts stylesheets; do \
		${INSTALL_DATA} ${WRKSRC}/$$i/*.* \
			${DESTDIR}${PREFIX}/${YENIHAT_DIR}/$$i; \
	done

.include "../../lang/ruby/rubyversion.mk"
.include "../../mk/bsd.pkg.mk"
