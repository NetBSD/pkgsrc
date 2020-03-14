# $NetBSD: Makefile,v 1.1 2020/03/14 04:26:39 tpaul Exp $

VERSION=	1.10.1
PKGNAME=	${PHP_PKG_PREFIX}-composer-${VERSION}
DISTNAME=	composer
CATEGORIES=	devel
MASTER_SITES=	https://getcomposer.org/download/${VERSION}/
DIST_SUBDIR=	php-composer/${VERSION}
EXTRACT_SUFX=	.phar

MAINTAINER=	tpaul@NetBSD.org
HOMEPAGE=	https://getcomposer.org/
COMMENT=	Dependency Manager for PHP
LICENSE=	mit

NO_BUILD=	yes
AUTO_MKDIRS=	yes

DEPENDS+=	${PHP_PKG_PREFIX}-mbstring-[0-9]*:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-json-[0-9]*:../../textproc/php-json
DEPENDS+=	${PHP_PKG_PREFIX}-zip-[0-9]*:../../archivers/php-zip

do-extract:
	${MKDIR} -m 0755 ${WRKSRC}
	${INSTALL} -m 0644 ${FILESDIR}/composer ${WRKSRC}/composer

do-install:
	${INSTALL} -m 0755 ${WRKSRC}/composer ${DESTDIR}${PREFIX}/bin/composer
	${INSTALL} -m 0644 ${DISTDIR}/${DIST_SUBDIR}/composer.phar \
		${DESTDIR}${PREFIX}/share/php/composer.phar

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		post-extract
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		composer
SUBST_VARS.fix-paths=		PREFIX

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
