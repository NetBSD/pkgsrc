# $NetBSD: Makefile,v 1.1 2015/07/06 04:31:27 rodent Exp $
#

THEME_NAME=	red-andy
DISTNAME=	${THEME_NAME}_1.00
PKGNAME=	${RUBY_PKGPREFIX}-redmine-${DISTNAME:S/_/-theme-/1}
MASTER_SITES=	http://projects.andriylesyuk.com/attachments/download/581/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://blog.andriylesyuk.com/${THEME_NAME}-1-00-the-first-responsive-theme-for-redmine/
COMMENT=	First responsive theme for Redmine
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${THEME_NAME}

.include "../../meta-pkgs/ruby-redmine-themes/Makefile.common"

REDANDY_DIR=		${REDMINE_THEMEDIR}/${THEME_NAME}

INSTALLATION_DIRS+=	${REDANDY_DIR}/images/mobile ${REDANDY_DIR}/javascripts
INSTALLATION_DIRS+=	${REDANDY_DIR}/stylesheets

do-install:
	for i in images javascripts stylesheets; do \
		${INSTALL_DATA} ${WRKSRC}/$$i/*.* \
			${DESTDIR}${PREFIX}/${REDANDY_DIR}/$$i; \
	done
	${INSTALL_DATA} ${WRKSRC}/images/mobile/* \
		${DESTDIR}${PREFIX}/${REDANDY_DIR}/images/mobile

.include "../../lang/ruby/rubyversion.mk"
.include "../../mk/bsd.pkg.mk"
