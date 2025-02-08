# $NetBSD: Makefile,v 1.31 2025/02/08 03:39:10 taca Exp $

VERSION=	2.2.18
PKGNAME=	${PHP_PKG_PREFIX}-composer-${VERSION}
PKGREVISION=	1
DISTNAME=	composer
CATEGORIES=	devel
MASTER_SITES=	https://getcomposer.org/download/${VERSION}/
DIST_SUBDIR=	php-composer/${VERSION}
EXTRACT_SUFX=	.phar

MAINTAINER=	tpaul@NetBSD.org
HOMEPAGE=	https://getcomposer.org/
COMMENT=	Dependency Manager for PHP
LICENSE=	mit

DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=${PHP_BASE_VERS}:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-zip>=${PHP_BASE_VERS}:../../archivers/php-zip

NO_BUILD=	yes

INSTALLATION_DIRS+=	bin ${PHP_SHAREDIR}

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		post-extract
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		composer${PHP_VER}
SUBST_VARS.fix-paths=		PREFIX PHP_VER PHP_SHAREDIR

do-extract:
	${MKDIR} -m 0755 ${WRKSRC}
	${INSTALL} -m 0644 ${FILESDIR}/composer ${WRKSRC}/composer${PHP_VER}

do-install:
	${INSTALL} -m 0755 ${WRKSRC}/composer${PHP_VER} ${DESTDIR}${PREFIX}/bin
	${INSTALL} -m 0644 ${DISTDIR}/${DIST_SUBDIR}/composer.phar \
		${DESTDIR}${PREFIX}/${PHP_SHAREDIR}

.include "../../lang/php/json.mk"
.include "../../mk/bsd.pkg.mk"
