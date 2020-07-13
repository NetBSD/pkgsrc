# $NetBSD: Makefile,v 1.3 2020/07/13 20:21:36 wiz Exp $

DISTNAME=	PurpleMine2-2.10.2
PKGNAME=	${RUBY_PKGPREFIX}-redmine-purplemine2-theme-${DISTNAME:S/PurpleMine2-//}
MASTER_SITES=	${MASTER_SITE_GITHUB:=mrliptontea/}
GITHUB_PROJECT=	PurpleMine2
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mrliptontea/PurpleMine2/
COMMENT=	Free Redmine theme for modern browsers
LICENSE=	mit

.include "../../meta-pkgs/ruby-redmine-themes/Makefile.common"

PM2_DIR=	${REDMINE_THEMEDIR}/purplemine2

INSTALLATION_DIRS+=	${PM2_DIR}/favicon ${PM2_DIR}/fonts ${PM2_DIR}/images
INSTALLATION_DIRS+=	${PM2_DIR}/javascripts ${PM2_DIR}/stylesheets

do-install:
	for i in favicon fonts images javascripts stylesheets; do \
		${INSTALL_DATA} ${WRKSRC}/$$i/*.* \
			${DESTDIR}${PREFIX}/${PM2_DIR}/$$i; \
	done

.include "../../lang/ruby/rubyversion.mk"
.include "../../mk/bsd.pkg.mk"
