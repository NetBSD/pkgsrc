# $NetBSD: Makefile,v 1.9 2019/06/10 02:48:23 jym Exp $
#

DISTNAME=	phoronix-test-suite-${PTS_VERSION}
PTS_VERSION=	8.8.1
CATEGORIES=	benchmarks
MASTER_SITES=	https://www.phoronix-test-suite.com/releases/

MAINTAINER=	jym@NetBSD.org
HOMEPAGE=	https://www.phoronix-test-suite.com/
COMMENT=	Phoronix Benchmarking Suite
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PHP_PKG_PREFIX}-curl>=5.3:../../www/php-curl
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=5.3:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-json>=5.3:../../textproc/php-json
DEPENDS+=	${PHP_PKG_PREFIX}-pcntl>=5.3:../../devel/php-pcntl
DEPENDS+=	${PHP_PKG_PREFIX}-posix>=5.3:../../devel/php-posix
DEPENDS+=	${PHP_PKG_PREFIX}-zip>=5.3:../../archivers/php-zip
DEPENDS+=	${PHP_PKG_PREFIX}-zlib>=5.3:../../archivers/php-zlib

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

pre-install:
	${FIND} ${WRKSRC} -name "*.orig" -print | ${XARGS} ${RM} -f

do-install:
	cd ${WRKSRC}/ && DESTDIR=${DESTDIR:Q} PKGMANDIR=${PKGMANDIR:Q} \
		./install-sh ${PREFIX:Q}

.include "../../lang/php/phpversion.mk"
.include "${PHPPKGSRCDIR}/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
