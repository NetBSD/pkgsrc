# $NetBSD: Makefile,v 1.6 2021/02/28 16:14:30 taca Exp $
#

DISTNAME=	minimalflat-${GITHUB_RELEASE}
PKGNAME=	${RUBY_PKGPREFIX}-redmine${RM_VER}-minimalflat-theme-${GITHUB_RELEASE:S/v//1}
MASTER_SITES=	${MASTER_SITE_GITHUB:=akabekobeko/}
GITHUB_PROJECT=	redmine-theme-minimalflat
GITHUB_RELEASE=	v1.0.2
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/akabekobeko/redmine-theme-minimalflat
COMMENT=	Minimal and flat design Redmine theme
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/ruby-redmine-themes/Makefile.common"

MINIMALFLAT_DIR=	${RM_THEMEDIR}/minimalflat

INSTALLATION_DIRS+=	${MINIMALFLAT_DIR}/fonts ${MINIMALFLAT_DIR}/javascripts
INSTALLATION_DIRS+=	${MINIMALFLAT_DIR}/stylesheets
WRKSRC=			${WRKDIR}/minimalflat

do-install:
	for i in fonts javascripts stylesheets; do \
		${INSTALL_DATA} ${WRKSRC}/$$i/* \
			${DESTDIR}${PREFIX}/${MINIMALFLAT_DIR}/$$i; \
	done

.include "../../lang/ruby/rubyversion.mk"
.include "../../mk/bsd.pkg.mk"
