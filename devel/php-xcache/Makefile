# $NetBSD: Makefile,v 1.3 2015/12/19 14:27:13 taca Exp $

MODNAME=	xcache
PECL_VERSION=	3.2.0
PKGREVISION=	1
CATEGORIES=	devel www
MASTER_SITES=	http://xcache.lighttpd.net/pub/Releases/${PECL_VERSION}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	vs@nifelheim.info
HOMEPAGE=	http://xcache.lighttpd.net/
COMMENT=	Fast and stable PHP opcode cacher
LICENSE=	modified-bsd

BUILD_DEPENDS+=	re2c>=0.13.0.4:../../devel/re2c

PHP_VERSIONS_ACCEPTED=	55 56

USE_LANGUAGES=		c c++
USE_TOOLS+=		gawk gm4 gsed pax
CONFIGURE_ARGS+=	--enable-${MODNAME}
USE_LIBTOOL=		yes

EGDIR=		share/examples/${PHP_PKG_PREFIX}-xcache
CONF_FILES=	${EGDIR}/xcache.ini ${PKG_SYSCONFDIR}/xcache.ini

XCACHE_DIR=		share/${PHP_PKG_PREFIX}-xcache
INSTALLATION_DIRS+=	${EGDIR} ${XCACHE_DIR}/cacher/lang
INSTALLATION_DIRS+=	${XCACHE_DIR}/cacher/sub ${XCACHE_DIR}/common/lang
INSTALLATION_DIRS+=	${XCACHE_DIR}/coverager/lang
INSTALLATION_DIRS+=	${XCACHE_DIR}/diagnosis/lang

PLIST_SRC+=		PLIST
PLIST_SUBST=		PHP_PKG_PREFIX=${PHP_PKG_PREFIX}
MESSAGE_SUBST=		PHP_PKG_PREFIX=${PHP_PKG_PREFIX}

.include "options.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/xcache.ini ${DESTDIR}${PREFIX}/${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/htdocs/*.php ${DESTDIR}${PREFIX}/${XCACHE_DIR}
	for i in cacher common coverager diagnosis; do \
		${INSTALL_DATA} ${WRKSRC}/htdocs/$$i/*.* \
			${DESTDIR}${PREFIX}/${XCACHE_DIR}/$$i; \
		${INSTALL_DATA} ${WRKSRC}/htdocs/$$i/lang/*.* \
			${DESTDIR}${PREFIX}/${XCACHE_DIR}/$$i/lang; \
	done
	${INSTALL_DATA} ${WRKSRC}/htdocs/cacher/sub/*.php \
		${DESTDIR}${PREFIX}/${XCACHE_DIR}/cacher/sub

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
