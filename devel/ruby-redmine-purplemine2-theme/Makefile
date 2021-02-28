# $NetBSD: Makefile,v 1.4 2021/02/28 16:20:55 taca Exp $

DISTNAME=	PurpleMine2-2.14.0
PKGNAME=	${RUBY_PKGPREFIX}-redmine${RM_VER}-purplemine2-theme-${DISTNAME:S/PurpleMine2-//}
MASTER_SITES=	${MASTER_SITE_GITHUB:=mrliptontea/}
GITHUB_PROJECT=	PurpleMine2
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mrliptontea/PurpleMine2/
COMMENT=	Free Redmine theme for modern browsers
LICENSE=	mit

.include "../../meta-pkgs/ruby-redmine-themes/Makefile.common"

PM2_DIR=	${RM_THEMEDIR}/purplemine2

INSTALLATION_DIRS+=	${PM2_DIR}/favicon ${PM2_DIR}/fonts ${PM2_DIR}/images
INSTALLATION_DIRS+=	${PM2_DIR}/javascripts ${PM2_DIR}/stylesheets

do-install:
	for i in favicon fonts images javascripts stylesheets; do \
		${INSTALL_DATA} ${WRKSRC}/$$i/*.* \
			${DESTDIR}${PREFIX}/${PM2_DIR}/$$i; \
	done

.include "../../lang/ruby/rubyversion.mk"
.include "../../mk/bsd.pkg.mk"
