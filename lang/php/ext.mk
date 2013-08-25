# $NetBSD: ext.mk,v 1.29.8.1 2013/08/25 16:56:44 tron Exp $
#
# PHP extension package framework, for both PECL and bundled PHP extensions.
#
# Just include this file, define MODNAME, define PKGREVISION if necessary,
# add dependencies, and add the appropriate --with-configure-arg, then include
# bsd.pkg.mk.

.if !defined(PHPEXT_MK)
PHPEXT_MK=	defined

_VARGROUPS+=		phpext
_USER_VARS.phpext=	# none
_PKG_VARS.phpext=	MODNAME PECL_VERSION PKGMODNAME MODULESDIR \
			USE_PHP_EXT_PATCHES
_SYS_VARS.phpext=	DISTINFO_FILE PATCHDIR

.if defined(PECL_VERSION)
HOMEPAGE?=		http://pecl.php.net/package/${MODNAME}
.endif

.include "../../lang/php/phpversion.mk"

.if defined(PHPPKGSRCDIR)
.include "${PHPPKGSRCDIR}/Makefile.common"
.endif

PKGMODNAME?=		${MODNAME:S/-/_/}
PHPSETUPSUBDIR?=	#empty
MODULESDIR?=		${WRKSRC}/modules
PLIST_SUBST+=		MODNAME=${PKGMODNAME}

.if !defined(PECL_VERSION)
# bundled extension
PKGNAME?=		${PHP_PKG_PREFIX}-${MODNAME}-${PHP_BASE_VERS}
EXTRACT_ELEMENTS?=	${DISTNAME}/ext/${PKGMODNAME}
WRKSRC?=		${WRKDIR}/${EXTRACT_ELEMENTS}
DISTINFO_FILE=		${.CURDIR}/${PHPPKGSRCDIR}/distinfo
.else
# PECL extension
# WARINING: following fixed version number for PHP 5.3.x must not be bumped!
.if defined(PECL_LEGACY_VERSION_SCHEME) && ${PKG_PHP_VERSION} == "53"
PKGNAME?=		${PHP_PKG_PREFIX}-${MODNAME}-5.3.9.${PECL_VERSION}
.else
PKGNAME?=		${PHP_PKG_PREFIX}-${MODNAME}-${PECL_VERSION}
.endif
MASTER_SITES?=		http://pecl.php.net/get/
PECL_DISTNAME?=		${MODNAME}-${PECL_VERSION}
DISTNAME=		${PECL_DISTNAME}
DIST_SUBDIR?=		php-${MODNAME}
EXTRACT_SUFX?=		.tgz
.endif

PHPIZE?=		${BUILDLINK_PREFIX.php}/bin/phpize
PHP_CONFIG?=		${BUILDLINK_PREFIX.php}/bin/php-config

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-php-config=${PHP_CONFIG}

USE_CONFIG_WRAPPER=	YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	YES
USE_TOOLS+=		automake

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}
MAKE_ENV+=		EXPORT_SYMBOLS_LDFLAGS="${EXPORT_SYMBOLS_LDFLAGS}"

PLIST_SRC+=		${.CURDIR}/../../lang/php/PLIST.module
MESSAGE_SRC=		${.CURDIR}/../../lang/php/MESSAGE.module
MESSAGE_SUBST+=		MODNAME=${PKGMODNAME}
MESSAGE_SUBST+=		PHP_EXTENSION_DIR=${PHP_EXTENSION_DIR}

# Also include extension-specific message
.if exists(${.CURDIR}/MESSAGE)
MESSAGE_SRC+=		${.CURDIR}/MESSAGE
.endif

.if ${OBJECT_FMT} == "SOM"
SHLIB_SUFFIX=		sl
.else
SHLIB_SUFFIX=		so
.endif

pre-configure:	phpize-module

phpize-module:
	@cookie=${WRKDIR}/.phpize_module_done;				\
	if [ ! -f $${cookie} ]; then					\
		cd ${WRKSRC}/${PHPSETUPSUBDIR} &&			\
		${SETENV}						\
			AUTOCONF=${TOOLS_DIR:Q}/bin/autoconf		\
			AUTOHEADER=${TOOLS_DIR:Q}/bin/autoheader	\
			ACLOCAL=${TOOLS_DIR:Q}/bin/aclocal		\
			LIBTOOLIZE=${LOCALBASE:Q}/bin/libtoolize	\
			${PHPIZE} &&					\
		${TOUCH} ${TOUCH_FLAGS} $${cookie};			\
	fi

do-install: do-module-install

do-module-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${PHP_EXTENSION_DIR}
	${INSTALL_LIB} ${MODULESDIR}/${PKGMODNAME}.${SHLIB_SUFFIX} \
		${DESTDIR}${PREFIX}/${PHP_EXTENSION_DIR}

.if defined(USE_PHP_EXT_PATCHES)
PATCHDIR=		${.CURDIR}/${PHPPKGSRCDIR}/patches
do-patch:
	${_PKG_SILENT}${_PKG_DEBUG}	\
	cd ${WRKSRC};			\
	for p in `${EGREP} -l '^\+\+\+ ext/${MODNAME}/' ${PATCHDIR}/patch-*`;do\
		${SED} -e 's,^+++ ext/${MODNAME}/,+++ ,' $$p | ${PATCH} ${PATCH_ARGS}; \
	done || ${TRUE}
.endif

.if defined(PHPPKGSRCDIR)
.include "${PHPPKGSRCDIR}/buildlink3.mk"
.endif

.endif	# PHPEXT_MK
