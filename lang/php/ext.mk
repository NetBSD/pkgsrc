# $NetBSD: ext.mk,v 1.5 2004/12/12 09:13:56 jdolecek Exp $
#
# PHP extension package framework, for both PECL and bundled PHP extensions.
#
# Just include this file, define MODNAME, define PKGREVISION if necessary,
# add dependencies, and add the appropriate --with-configure-arg, then include
# bsd.pkg.mk.

.if !defined(PHPEXT_MK)
PHPEXT_MK=	defined

.include "../../lang/php/phpversion.mk"

.include "${PHPPKGSRCDIR}/Makefile.common"

PKGMODNAME?=		${MODNAME:S/-/_/}
MODULESDIR?=		${WRKSRC}/modules
PLIST_SUBST+=		MODNAME=${PKGMODNAME}

.if !defined(PECL_VERSION)
# bundled extension
PKGNAME?=		php-${MODNAME}-${PHP_BASE_VERS}
EXTRACT_ELEMENTS?=	${DISTNAME}/ext/${PKGMODNAME}
WRKSRC?=		${WRKDIR}/${EXTRACT_ELEMENTS}
DISTINFO_FILE=		${.CURDIR}/${PHPPKGSRCDIR}/distinfo
.else
# PECL extension
PKGNAME?=		php-${MODNAME}-${PHP_BASE_VERS}.${PECL_VERSION}
MASTER_SITES=		http://pecl.php.net/get/
DISTNAME=		${MODNAME}-${PECL_VERSION}
DIST_SUBDIR=		php-${MODNAME}
EXTRACT_SUFX=		.tgz
.endif

PHPIZE?=		${BUILDLINK_PREFIX.php}/bin/phpize
PHP_CONFIG?=		${BUILDLINK_PREFIX.php}/bin/php-config

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-php-config=${PHP_CONFIG}

USE_CONFIG_WRAPPER=	YES
USE_LIBTOOL=		YES

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}
MAKE_ENV+=		EXPORT_SYMBOLS_LDFLAGS="${EXPORT_SYMBOLS_LDFLAGS}"

PLIST_SRC+=		${.CURDIR}/../../lang/php/PLIST.module
MESSAGE_SRC=		${.CURDIR}/../../lang/php/MESSAGE.module
MESSAGE_SUBST+=		MODNAME=${PKGMODNAME}
MESSAGE_SUBST+=		PHP_EXTENSION_DIR=${PHP_EXTENSION_DIR}

pre-configure:	phpize-module

phpize-module:
	@cookie=${WRKDIR}/.phpize_module_done;				\
	if [ ! -f $${cookie} ]; then					\
		cd ${WRKSRC} && 					\
		${SETENV} AUTOCONF=${AUTOCONF} AUTOHEADER=${AUTOHEADER}	\
			ACLOCAL=${ACLOCAL}				\
			LIBTOOLIZE=${LOCALBASE}/bin/libtoolize		\
			${PHPIZE} &&					\
		${TOUCH} ${TOUCH_FLAGS} $${cookie};			\
	fi

do-install: do-module-install

do-module-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${PHP_EXTENSION_DIR}
	${INSTALL_DATA} ${MODULESDIR}/${PKGMODNAME}.so \
		${PREFIX}/${PHP_EXTENSION_DIR}

.if defined(USE_PHP_EXT_PATCHES)
PATCHDIR=		${.CURDIR}/${PHPPKGSRCDIR}/patches
do-patch:
	cd ${WRKSRC}; \
	for p in `${EGREP} -l '^\+\+\+ ext/${MODNAME}/' ${PATCHDIR}/patch-*`;do\
		${SED} -e 's,^+++ ext/${MODNAME}/,+++ ,' $$p | ${PATCH}; \
	done
.endif

.include "../../mk/automake.mk"
.include "${PHPPKGSRCDIR}/buildlink3.mk"

.endif	# PHPEXT_MK
