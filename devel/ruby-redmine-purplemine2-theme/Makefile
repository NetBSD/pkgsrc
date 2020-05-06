# $NetBSD: Makefile,v 1.2 2020/05/06 14:53:30 taca Exp $

DISTNAME=	${GITHUB_TAG}
PKGNAME=	${RUBY_PKGPREFIX}-redmine-${GITHUB_PROJECT:tl}-theme-${DISTNAME:S/v//1}
MASTER_SITES=	${MASTER_SITE_GITHUB:=mrliptontea/}
GITHUB_PROJECT=	PurpleMine2
GITHUB_TAG=	v2.10.2
DIST_SUBDIR=	ruby-redmine-${GITHUB_PROJECT:tl}-theme

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mrliptontea/PurpleMine2/
COMMENT=	Free Redmine theme for modern browsers
LICENSE=	mit

.include "../../meta-pkgs/ruby-redmine-themes/Makefile.common"

WRKSRC=		${WRKDIR}/PurpleMine2-${GITHUB_TAG:S/v//}

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
