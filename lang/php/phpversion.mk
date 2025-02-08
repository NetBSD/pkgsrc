# $NetBSD: phpversion.mk,v 1.453 2025/02/08 02:56:24 taca Exp $
#
# This file selects a PHP version, based on the user's preferences and
# the installed packages. It does not add a dependency on the PHP
# package.
#
# === User-settable variables ===
#
# PHP_VERSION_DEFAULT
#	The PHP version to choose when more than one is acceptable to
#	the package.
#
#	Possible: 56 74 81 82 83
#	Default: 82
#
# === Infrastructure variables ===
#
# PHP_VERSION_REQD
#	PHP version to use. This variable should not be set in
#	packages.  Normally it is used by bulk build tools.
#
#	Possible: ${PHP_VERSIONS_ACCEPTED}
#	Default:  ${PHP_VERSION_DEFAULT}
#
# === Package-settable variables ===
#
# PHP_VERSIONS_ACCEPTED
#	The PHP versions that are accepted by the package.
#
#	Possible: 56 74 81 82 83
#	Default: 82 81 83 74 56
#
# PHP_VERSIONS_INCOMPATIBLE
#	The PHP versions that are not supported by the package.
#
#	Possible: 56 74 81 82 83
#	Default: (empty)
#
# PHP_MINIMUM_TEENY
#	Minimum teeny version for a pacakge.
#
# === Variables defined by this file ===
#
# PHP_VER
#	The selected PHP version.
#
#	Possible: 56 74 81 82 83
#	Default: ${PHP_VERSION_DEFAULT}
#
# PHP_VERSION
#	The selected PHP's full version.
#
# PHP_BASE_VERS
#	Minimum version PHP's full version with selected PHP
#	and PHP_MINIMUM_TEENY.
#
# PHP_MAJOR_VERS
#	The selected PHP's major version.
#
#	Possible: 5 7 8
#	Default: 8
#
# PHP_MINOR_VERS
#	The selected PHP's minor version.
#
# PHPPKGSRCDIR
#	The directory of the PHP implementation, relative to the
#	package directory.
#
#	Example: ../../lang/php82
#
# PHP_PKG_PREFIX
#	The prefix that is prepended to the package name.
#
#	Example: php56 php74 php81 php82 php83
#
# PHP_INCDIR
#	PHP include directory path relative to ${PREFIX}.
#
#	Example: include/php/8.2
#
# PHP_LIBDIR
#	PHP library directory path relative to ${PREFIX}.
#
#	Example: lib/php/8.2
#
# PHP_EGDIR
#	PHP example directory path relative to ${PREFIX}.
#
#	Example: share/example/php/8.2
#
# PHP_SHAREDIR
#	PHP share directory path relative to ${PREFIX}.
#
#	Example: share/share/php/8.2
#
#
# PHP_EXTENSION_DIR
#	Relative path to ${PREFIX} for PHP's extensions.  It is derived from
#	MACHINE_GNU_ARCH.
#
#	Example: lib/php/8.3/x86_64
#
# Keywords: php
#

.if !defined(PHPVERSION_MK)
PHPVERSION_MK=	defined

# Define each PHP's version.
PHP56_VERSION=	5.6.40
PHP74_VERSION=	7.4.33
PHP81_VERSION=	8.1.31
PHP82_VERSION=	8.2.27
PHP83_VERSION=	8.3.16

_VARGROUPS+=	php
_USER_VARS.php=	PHP_VERSION_DEFAULT
_PKG_VARS.php=	PHP_VERSIONS_ACCEPTED PHP_VERSION_REQD
_SYS_VARS.php=	PHP_VERSION_PHP PHPPKGSRCDIR PHP_PKG_PREFIX PHP_VER PHP_MAJOR_VERS

.include "../../mk/bsd.prefs.mk"

PHP_VERSION_DEFAULT?=		82
PHP_VERSIONS_ACCEPTED?=		82 81 83 74 56
.for pv in ${PHP_VERSIONS_ACCEPTED}
.  if empty(PHP_VERSIONS_INCOMPATIBLE:M${pv})
_PHP_VERSIONS_ACCEPTED+=	${pv}
.  endif
.endfor

# transform the list into individual variables
.for pv in ${_PHP_VERSIONS_ACCEPTED}
_PHP_VERSION_${pv}_OK=	yes
.endfor

# if a version is explicitly required, take it
.if defined(PHP_VERSION_REQD)
_PHP_VERSION=	${PHP_VERSION_REQD}
.endif
# prefer an already installed version, in order of "accepted"
.if !defined(_PHP_VERSION)
.for pv in ${_PHP_VERSIONS_ACCEPTED}
# keep information as last resort - see below
_PHP_VERSION_FIRSTACCEPTED?=	${pv}
.endfor
.endif
# if the default is OK for the add-on pkg, take this
.if !defined(_PHP_VERSION)
.if defined(_PHP_VERSION_${PHP_VERSION_DEFAULT}_OK)
_PHP_VERSION=	${PHP_VERSION_DEFAULT}
.endif
.endif
# take the first one accepted by the package
.if !defined(_PHP_VERSION)
_PHP_VERSION=	${_PHP_VERSION_FIRSTACCEPTED}
.endif

#
# Variable assignment for multi-PHP packages
MULTI+=	PHP_VERSION_REQD=${_PHP_VERSION}

#
# set variables for the version we decided to use:
#
.if ${_PHP_VERSION} == 56
PHP_VERSION=		${PHP56_VERSION}
PHP_MINIMUM_TEENY=	3
.elif ${_PHP_VERSION} == 74
PHP_VERSION=		${PHP74_VERSION}
.elif ${_PHP_VERSION} == 81
PHP_VERSION=		${PHP81_VERSION}
.elif ${_PHP_VERSION} == 82
PHP_VERSION=		${PHP82_VERSION}
.elif ${_PHP_VERSION} == 83
PHP_VERSION=		${PHP83_VERSION}
.else
# force an error
PKG_FAIL_REASON+=	"${_PHP_VERSION} is not a valid package"
.endif

# PHP minimum teeny version for a package.
PHP_MINIMUM_TEENY?=	0

# PHP major version
PHP_MAJOR_VERS=		${PHP_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\1/}

# PHP minor version
PHP_MINOR_VERS=		${PHP_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\2/}

# export some of the internal variables
PHP_VER:=		${PHP_MAJOR_VERS}${PHP_MINOR_VERS}

# PHP minimum version
PHP_BASE_VERS?=	${PHP_MAJOR_VERS}.${PHP_MINOR_VERS}.${PHP_MINIMUM_TEENY}

# PHP API version; initial 
PHP_API_VERS?=	${PHP_MAJOR_VERS}.${PHP_MINOR_VERS}

PHPPKGSRCDIR=		../../lang/php${PHP_VER}

PHP_PKG_PREFIX=		php${PHP_VER}
PHP_NAME=		php${PHP_VER}

PHPIZE?=		${PREFIX}/bin/phpize${PHP_VER}
PHP_CONFIG?=		${PREFIX}/bin/php-config${PHP_VER}

# force the selected PHP version for recursive builds
PHP_VERSION_REQD:=	${PHP_VER}

PHP_INCDIR=		include/php/${PHP_API_VERS}
PHP_LIBDIR=		lib/php/${PHP_API_VERS}
PHP_EGDIR=		share/examples/php/${PHP_API_VERS}
PHP_SHAREDIR=		share/php/${PHP_API_VERS}

PHP_EXTENSION_DIR=	${PHP_LIBDIR}/${MACHINE_GNU_ARCH}

PKG_SYSCONFSUBDIR?=	php/${PHP_API_VERS}

MAKE_ENV+=		PHP_VERSION_REQD="${PHP_VER}" \
			PHP_VER="${PHP_VER}" PHP_API_VERS="${PHP_API_VERS}" \
			PHP_INCDIR="${PHP_INCDIR}" \
			PHP_LIBDIR="${PHP_LIBDIR}" PHP_EGDIR="${PHP_EGDIR}" \
			PHP_SHAREDIR="${PHP_SHAREDIR}" \
			PHP_EXTENSION_DIR="${PHP_EXTENSION_DIR}"
MAKEFLAGS+=		PHP_VERSION_REQD="${PHP_VER}"
FILES_SUBST+=		PHP_VER="${PHP_VER}" PHP_API_VERS="${PHP_API_VERS}" \
			PHP_INCDIR="${PHP_INCDIR}" \
			PHP_LIBDIR="${PHP_LIBDIR}" PHP_EGDIR="${PHP_EGDIR}" \
			PHP_SHAREDIR="${PHP_SHAREDIR}" \
			PHP_EXTENSION_DIR="${PHP_EXTENSION_DIR}"
MESSAGE_SUBST+=		PHP_VER=${PHP_VER} PHP_API_VERS="${PHP_API_VERS}" \
			PHP_INCDIR="${PHP_INCDIR}" \
			PHP_LIBDIR="${PHP_LIBDIR}" PHP_EGDIR="${PHP_EGDIR}" \
			PHP_SHAREDIR="${PHP_SHAREDIR}" \
			PHP_EXTENSION_DIR="${PHP_EXTENSION_DIR}"
PLIST_SUBST+=		PHP_PKG_PREFIX="${PHP_PKG_PREFIX}" \
			PHP_VER="${PHP_VER}" \
			PHP_MAJOR_VERS="${PHP_MAJOR_VERS}" \
			PHP_INCDIR="${PHP_INCDIR}" \
			PHP_LIBDIR="${PHP_LIBDIR}" PHP_EGDIR="${PHP_EGDIR}" \
			PHP_SHAREDIR="${PHP_SHAREDIR}" \
			PHP_EXTENSION_DIR="${PHP_EXTENSION_DIR}"

# fix shebang line.
#
# REPLACE_PHP		replace shebang line of specified files.
#
.if defined(REPLACE_PHP)
REPLACE_INTERPRETER+=	${PHP_NAME}

REPLACE.${PHP_NAME}.old=	.*php
REPLACE.${PHP_NAME}.new=	${PREFIX}/bin/php${PHP_VER}
REPLACE_FILES.${PHP_NAME}=	${REPLACE_PHP}

.endif # defined(REPLACE_PHP)

MAKEFLAGS+=	PHP_VERSION_REQD=${PHP_VERSION_REQD}

.endif	# PHPVERSION_MK
