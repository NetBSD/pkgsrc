# $NetBSD: Makefile,v 1.1 2020/05/06 13:50:39 taca Exp $
#

DISTNAME=	minimalflat2-${GITHUB_RELEASE:S/v//1}
PKGNAME=	${RUBY_PKGPREFIX}-redmine-minimalflat2-theme-${GITHUB_RELEASE:S/v//1}
MASTER_SITES=	${MASTER_SITE_GITHUB:=akabekobeko/}
GITHUB_PROJECT=	redmine-theme-minimalflat2
GITHUB_RELEASE=	v1.7.0
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/akabekobeko/redmine-theme-minimalflat2
COMMENT=	Minimal and flat design theme for Redmine
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/ruby-redmine-themes/Makefile.common"

MINIMALFLAT_DIR=	${REDMINE_THEMEDIR}/minimalflat2
MINIMALFLAT_SUBDIRS=	favicon fonts images javascripts stylesheets
WRKSRC=			${WRKDIR}/minimalflat2

.for d in ${MINIMALFLAT_SUBDIRS}
INSTALLATION_DIRS+=	${MINIMALFLAT_DIR}/${d}
.endfor

do-install:
	for i in ${MINIMALFLAT_SUBDIRS}; do \
		${INSTALL_DATA} ${WRKSRC}/$$i/* \
			${DESTDIR}${PREFIX}/${MINIMALFLAT_DIR}/$$i; \
	done

.include "../../lang/ruby/rubyversion.mk"
.include "../../mk/bsd.pkg.mk"
