# $NetBSD: Makefile,v 1.6 2013/03/16 07:21:19 obache Exp $
#

DISTNAME=	phoronix-test-suite-${PTS_VERSION}
PTS_VERSION=	3.4.0
PKGREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.phoronix-test-suite.com/releases/

MAINTAINER=	jym@NetBSD.org
HOMEPAGE=	http://www.phoronix-test-suite.com/
COMMENT=	Phoronix Benchmarking Suite
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PHP_PKG_PREFIX}-curl>=5.2:../../www/php-curl
DEPENDS+=	${PHP_PKG_PREFIX}-dom>=5.2:../../textproc/php-dom
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=5.2:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-json>=5.2:../../textproc/php-json
DEPENDS+=	${PHP_PKG_PREFIX}-pcntl>=5.2:../../devel/php-pcntl
DEPENDS+=	${PHP_PKG_PREFIX}-posix>=5.2:../../devel/php-posix
DEPENDS+=	${PHP_PKG_PREFIX}-zip>=5.2:../../archivers/php-zip
DEPENDS+=	${PHP_PKG_PREFIX}-zlib>=5.2:../../archivers/php-zlib

INSTALLATION_DIRS=	bin
INSTALLATION_DIRS+=	share/bash-completion.d
INSTALLATION_DIRS+=	share/doc/phoronix-test-suite
INSTALLATION_DIRS+=	share/applications share/icons/hicolor/64x64/apps

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/phoronix-test-suite

pre-install:
	${FIND} ${WRKSRC} -name "*.orig" -print | ${XARGS} ${RM} -f

do-install:
	cd ${WRKSRC}/ && DESTDIR=${DESTDIR:Q} ./install-sh ${PREFIX:Q}

.include "../../lang/php/phpversion.mk"
.include "${PHPPKGSRCDIR}/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
