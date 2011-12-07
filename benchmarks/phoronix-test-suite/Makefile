# $NetBSD: Makefile,v 1.2 2011/12/07 00:34:26 jym Exp $
#

DISTNAME=	phoronix-test-suite-${PTS_VERSION}
PTS_VERSION=	3.4.0
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.phoronix-test-suite.com/releases/

MAINTAINER=	jym@NetBSD.org
HOMEPAGE=	http://www.phoronix-test-suite.com/
COMMENT=	Phoronix Benchmarking Suite
LICENSE=	gnu-gpl-v3

DEPENDS+=	php>=${PHP_BASE_VERS}<5.4:../../lang/php53
DEPENDS+=	php53-curl>=${PHP_BASE_VERS}<5.4:../../www/php-curl
DEPENDS+=	php53-dom>=${PHP_BASE_VERS}<5.4:../../textproc/php-dom
DEPENDS+=	php53-gd>=${PHP_BASE_VERS}<5.4:../../graphics/php-gd
DEPENDS+=	php53-json>=${PHP_BASE_VERS}<5.4:../../textproc/php-json
DEPENDS+=	php53-pcntl>=${PHP_BASE_VERS}<5.4:../../devel/php-pcntl
DEPENDS+=	php53-posix>=${PHP_BASE_VERS}<5.4:../../devel/php-posix
DEPENDS+=	php53-zip>=${PHP_BASE_VERS}<5.4:../../archivers/php-zip
DEPENDS+=	php53-zlib>=${PHP_BASE_VERS}<5.4:../../archivers/php-zlib

PKG_DESTDIR_SUPPORT=	user-destdir

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

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
