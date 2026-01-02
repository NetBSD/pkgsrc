# $NetBSD: Makefile,v 1.70 2026/01/02 09:09:36 taca Exp $
#
# This is super confusing, but the PEAR tarball does not include an installer,
# it is only available in a different installer package which bundles the PEAR
# tarball along with its dependencies.  So our distfile is pearweb_phars, and
# we override the version to whatever PEAR it bundles.
#

DISTNAME=	pearweb_phars-1.10.25
PKGNAME=	${PHP_PKG_PREFIX}-pear-1.10.17
CATEGORIES=	lang
MASTER_SITES=	http://download.pear.php.net/package/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pear.php.net/
COMMENT=	PEAR Base System for PHP
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

.include "../../lang/php/common.mk"

CONFLICTS+=	php<5.2.1nb2

PKG_SYSCONFVAR=	php
CONF_FILES=	${PREFIX}/${PHP_EGDIR}/pear.conf \
		${PKG_SYSCONFDIR}/pear.conf

SUBST_CLASSES+=		config
SUBST_STAGE.config=	pre-configure
SUBST_FILES.config=	src/PEAR/Start.php ${WRKDIR}/README.pkgsrc
SUBST_VARS.config+=	PHP_LIBDIR PKGMANDIR PREFIX WRKSRC PHP_VER
SUBST_MESSAGE.config=	Fixing configuration files.

PEAR_COMMANDS=		pear peardev pecl
INSTALLATION_DIRS+=	${PHP_EGDIR} ${PHP_SHAREDIR}

# TODO: This should probably be set in lang/php
PHPBIN=		${PREFIX}/bin/php${PHP_VER}

# Unpack the .phar archive so that we can patch the source files.
post-extract:
	cd ${WRKSRC} && ${PHPBIN} -d phar.readonly=0 -r \
		'$$p = new Phar("go-pear.phar"); \
		 $$p->extractTo("src");'
	${MV} ${WRKSRC}/go-pear.phar ${WRKSRC}/go-pear-orig.phar
	${CP} ${FILESDIR}/README.pkgsrc ${WRKDIR}

# This does not actually build anything, just packs our patched source files
# back to an updated .phar.
do-build:
	cd ${WRKSRC} && ${PHPBIN} -d phar.readonly=0 -r \
		'$$p = new Phar("go-pear.phar", 0, "go-pear.phar"); \
		 $$p->buildFromDirectory(dirname(__FILE__) . "/src"); \
		 $$p->setStub($$p->createDefaultStub("index.php"));'

INSTALL_ENV+=	PHP_PEAR_PHP_BIN=${PHPBIN}

do-install:
	cd ${WRKSRC} && \
		${PKGSRC_SETENV} ${INSTALL_ENV} ${PHPBIN} go-pear.phar
	${INSTALL_DATA} ${WRKSRC}/pear.conf \
		${DESTDIR}${PREFIX}/${PHP_EGDIR}/pear.conf
	${INSTALL_DATA} ${WRKDIR}/README.pkgsrc \
		${DESTDIR}${PREFIX}/${PHP_SHAREDIR}

post-install:
	cd ${DESTDIR}${PREFIX}/bin && for f in ${PEAR_COMMANDS}; do \
		${MV} -f $${f} $${f}${PHP_VER}; \
	done

.include "${PHPPKGSRCDIR}/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
