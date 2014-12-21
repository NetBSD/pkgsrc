# $NetBSD: phpversion.mk,v 1.73.2.6 2014/12/21 16:19:39 tron Exp $
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
#	Possible: 53 54 55
#	Default: 54
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
#	Possible: 53 54 55
#	Default: 54 53
#
# PHP_CHECK_INSTALLED
#	Check installed version of PHP.  Should be used lang/php53,
#	lang/php54 and lang/php55 only.
#
#	Possible: Yes No
#	Default: Yes
#
# === Variables defined by this file ===
#
# PKG_PHP_VERSION
#	The selected PHP version.
#
#	Possible: 53 54 55
#	Default: ${PHP_VERSION_DEFAULT}
#
# PHP_BASE_VERS
#	The selected PHP's full version depends on PKG_PHP_VERSION
#
# PKG_PHP_MAJOR_VERS
#	The selected PHP's major version.
#
#	Possible: 5
#	Default: 5
#
# PKG_PHP
#	The same as ${PKG_PHP_VERSION}, prefixed with "php-".
#
# PHPPKGSRCDIR
#	The directory of the PHP implementation, relative to the
#	package directory.
#
#	Example: ../../lang/php54
#
# PHP_PKG_PREFIX
#	The prefix that is prepended to the package name.
#
#	Example: php53, php54, php55
#
# PHP_EXTENSION_DIR
#	Relative path to ${PREFIX} for PHP's extensions.  It is derived from
#	initial release of major version.
#
#	Example: lib/php/20090630
#
# Keywords: php
#

.if !defined(PHPVERSION_MK)
PHPVERSION_MK=	defined

# Define each PHP's version.
PHP53_VERSION=	5.3.29
PHP54_VERSION=	5.4.36
PHP55_VERSION=	5.5.20

# Define initial release of major version.
PHP53_RELDATE=	20090630
PHP54_RELDATE=	20120301
PHP55_RELDATE=	20130620

_VARGROUPS+=	php
_USER_VARS.php=	PHP_VERSION_DEFAULT
_PKG_VARS.php=	PHP_VERSIONS_ACCEPTED PHP_VERSION_REQD
_SYS_VARS.php=	PKG_PHP_VERSION PKG_PHP PHPPKGSRCDIR PHP_PKG_PREFIX \
		PKG_PHP_MAJOR_VERS

.include "../../mk/bsd.prefs.mk"

PHP_VERSION_DEFAULT?=		54
PHP_VERSIONS_ACCEPTED?=		54 55 53

# transform the list into individual variables
.for pv in ${PHP_VERSIONS_ACCEPTED}
_PHP_VERSION_${pv}_OK=	yes
.endfor

# check what is installed
.if exists(${LOCALBASE}/lib/php/20130620)
_PHP_VERSION_55_INSTALLED=	yes
_PHP_INSTALLED=			yes
.elif exists(${LOCALBASE}/lib/php/20120301)
_PHP_VERSION_54_INSTALLED=	yes
_PHP_INSTALLED=			yes
.elif exists(${LOCALBASE}/lib/php/20090626) || exists(${LOCALBASE}/include/php/Zend/zend_gc.h)
_PHP_VERSION_53_INSTALLED=	yes
_PHP_INSTALLED=			yes
.endif

# if a version is explicitely required, take it
.if defined(PHP_VERSION_REQD)
_PHP_VERSION=	${PHP_VERSION_REQD}
.endif
# if the default is already installed, it is first choice
.if !defined(_PHP_VERSION)
.if defined(_PHP_VERSION_${PHP_VERSION_DEFAULT}_OK)
.if defined(_PHP_VERSION_${PHP_VERSION_DEFAULT}_INSTALLED)
_PHP_VERSION=	${PHP_VERSION_DEFAULT}
.endif
.endif
.endif
# prefer an already installed version, in order of "accepted"
.if !defined(_PHP_VERSION)
.for pv in ${PHP_VERSIONS_ACCEPTED}
.if defined(_PHP_VERSION_${pv}_INSTALLED)
_PHP_VERSION?=	${pv}
.else
# keep information as last resort - see below
_PHP_VERSION_FIRSTACCEPTED?=	${pv}
.endif
.endfor
.endif
# if the default is OK for the addon pkg, take this
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

# export some of internal variables
PKG_PHP_VERSION:=	${_PHP_VERSION:C/\.[0-9]//}
PKG_PHP:=		PHP${_PHP_VERSION:C/([0-9])([0-9])/\1.\2/}

# currently we have only PHP 5.x packages.
PKG_PHP_MAJOR_VERS:=	5

PHP_CHECK_INSTALLED?=	Yes

# if installed PHP isn't compatible with required PHP, bail out
.if empty(PHP_CHECK_INSTALLED:M[nN][oO])
.if defined(_PHP_INSTALLED) && !defined(_PHP_VERSION_${_PHP_VERSION}_INSTALLED)
PKG_SKIP_REASON+=	"Package accepts ${PKG_PHP}, but different version is installed"
.endif
.endif

MESSAGE_SUBST+=		PKG_PHP_VERSION=${PKG_PHP_VERSION} \
			PKG_PHP=${PKG_PHP}
PLIST_SUBST+=		PKG_PHP_VERSION=${PKG_PHP_VERSION} \
			PKG_PHP_MAJOR_VERS=${PKG_PHP_MAJOR_VERS} \
			PHP_EXTENSION_DIR=${PHP_EXTENSION_DIR}

# force the selected PHP version for recursive builds
PHP_VERSION_REQD:=	${PKG_PHP_VERSION}

#
# set variables for the version we decided to use:
#
.if ${_PHP_VERSION} == "53"
PHPPKGSRCDIR=		../../lang/php53
PHP_BASE_VERS=		${PHP53_VERSION}
PHP_PKG_PREFIX=		php53
PHP_EXTENSION_DIR=	lib/php/${PHP53_RELDATE}
.elif ${_PHP_VERSION} == "54"
PHPPKGSRCDIR=		../../lang/php54
PHP_BASE_VERS=		${PHP54_VERSION}
PHP_PKG_PREFIX=		php54
PHP_EXTENSION_DIR=	lib/php/${PHP54_RELDATE}
.elif ${_PHP_VERSION} == "55"
PHPPKGSRCDIR=		../../lang/php55
PHP_BASE_VERS=		${PHP55_VERSION}
PHP_PKG_PREFIX=		php55
PHP_EXTENSION_DIR=	lib/php/${PHP55_RELDATE}
.else
# force an error
PKG_SKIP_REASON+=	"${PKG_PHP} is not a valid package"
.endif

#
# check installed version aginst required:
#
.if !empty(PHP_CHECK_INSTALLED:M[nN][oO])
.if defined(_PHP_VERSION_INSTALLED) && ${_PHP_VERSION} != ${_PHP_VERSION_INSTALLED}
PKG_SKIP_REASON+=	"${PKGBASE} requires ${PKG_PHP}, but php-${_PHP_VERSION_INSTALLED} is already installed."
.endif
.endif

.endif	# PHPVERSION_MK
