# $NetBSD: Makefile,v 1.14 2025/02/08 03:28:48 taca Exp $
#

DISTNAME=	phoronix-test-suite-${PTS_VERSION}
PTS_VERSION=	8.8.1
PKGREVISION=	4
CATEGORIES=	benchmarks
MASTER_SITES=	https://www.phoronix-test-suite.com/releases/

MAINTAINER=	jym@NetBSD.org
HOMEPAGE=	https://www.phoronix-test-suite.com/
COMMENT=	Phoronix Benchmarking Suite
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PHP_PKG_PREFIX}-curl>=${PHP_BASE_VERS}:../../www/php-curl
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=${PHP_BASE_VERS}:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-pcntl>=${PHP_BASE_VERS}:../../devel/php-pcntl
DEPENDS+=	${PHP_PKG_PREFIX}-posix>=${PHP_BASE_VERS}:../../devel/php-posix
DEPENDS+=	${PHP_PKG_PREFIX}-zip>=${PHP_BASE_VERS}:../../archivers/php-zip
DEPENDS+=	${PHP_PKG_PREFIX}-zlib>=${PHP_BASE_VERS}:../../archivers/php-zlib

INSTALLATION_DIRS=	bin
INSTALLATION_DIRS+=	share/bash-completion.d
INSTALLATION_DIRS+=	share/phoronix-test-suite
INSTALLATION_DIRS+=	share/doc/phoronix-test-suite
INSTALLATION_DIRS+=	share/appdata share/applications
INSTALLATION_DIRS+=	share/icons/hicolor/48x48/apps share/mime/packages
INSTALLATION_DIRS+=	share/icons/hicolor/64x64/mimetypes

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/phoronix-test-suite

ICON_THEMES=	yes

PLIST_VARS+=	systemd

.if exists(/bin/systemd)
PLIST.systemd=	yes
.endif

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths+=	phoronix-test-suite
SUBST_VARS.paths+=	PREFIX PHP_VER

pre-install:
	${FIND} ${WRKSRC} -name "*.orig" -print | ${XARGS} ${RM} -f

do-install:
	cd ${WRKSRC}/ && DESTDIR=${DESTDIR:Q} PKGMANDIR=${PKGMANDIR:Q} \
		./install-sh ${PREFIX:Q}

.include "../../lang/php/json.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
