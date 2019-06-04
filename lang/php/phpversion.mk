# $NetBSD: phpversion.mk,v 1.251.2.7 2019/06/04 17:42:36 spz Exp $
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
#	Possible: 56 71 72 73
#	Default: 71
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
#	Possible: 56 71 72 73
#	Default: 71
#
# PHP_VERSIONS_INCOMPATIBLE
#	The PHP versions that are not supported by the package.
#
#	Possible: 56 71 72 73
#	Default: (empty)
#
# PHP_CHECK_INSTALLED
#	Check installed version of PHP.  Should be used by lang/php56,
#	lang/php71, lang/php72 or lang/php73 only.
#
#	Possible: Yes No
#	Default: Yes
#
# === Variables defined by this file ===
#
# PKG_PHP_VERSION
#	The selected PHP version.
#
#	Possible: 56 71 72 73
#	Default: ${PHP_VERSION_DEFAULT}
#
# PHP_BASE_VERS
#	The selected PHP's full version depends on PKG_PHP_VERSION
#
# PKG_PHP_MAJOR_VERS
#	The selected PHP's major version.
#
#	Possible: 5 7
#	Default: 7
#
# PKG_PHP
#	The same as ${PKG_PHP_VERSION}, prefixed with "php-".
#
# PHPPKGSRCDIR
#	The directory of the PHP implementation, relative to the
#	package directory.
#
#	Example: ../../lang/php71
#
# PHP_PKG_PREFIX
#	The prefix that is prepended to the package name.
#
#	Example: php56 php71 php72 php73
#
# PHP_EXTENSION_DIR
#	Relative path to ${PREFIX} for PHP's extensions.  It is derived from
#	initial release of major version.
#
#	Example: lib/php/20140828
#
# Keywords: php
#

.if !defined(PHPVERSION_MK)
PHPVERSION_MK=	defined

# Define each PHP's version.
PHP56_VERSION=	5.6.40
PHP71_VERSION=	7.1.30
PHP72_VERSION=	7.2.18
PHP73_VERSION=	7.3.5

# Define initial release of major version.
PHP56_RELDATE=	20140828
PHP71_RELDATE=	20160303
PHP72_RELDATE=	20170718
PHP73_RELDATE=	20181200

_VARGROUPS+=	php
_USER_VARS.php=	PHP_VERSION_DEFAULT
_PKG_VARS.php=	PHP_VERSIONS_ACCEPTED PHP_VERSION_REQD
_SYS_VARS.php=	PKG_PHP_VERSION PKG_PHP PHPPKGSRCDIR PHP_PKG_PREFIX \
		PKG_PHP_MAJOR_VERS

.include "../../mk/bsd.prefs.mk"

PHP_VERSION_DEFAULT?=		71
PHP_VERSIONS_ACCEPTED?=		56 71 72 73
.for pv in ${PHP_VERSIONS_ACCEPTED}
.  if empty(PHP_VERSIONS_INCOMPATIBLE:M${pv})
_PHP_VERSIONS_ACCEPTED+=	${pv}
.  endif
.endfor

# transform the list into individual variables
.for pv in ${_PHP_VERSIONS_ACCEPTED}
_PHP_VERSION_${pv}_OK=	yes
.endfor

# check what is installed
.if exists(${LOCALBASE}/lib/php/${PHP73_RELDATE})
_PHP_VERSION_73_INSTALLED=	yes
_PHP_INSTALLED=			yes
.elif exists(${LOCALBASE}/lib/php/${PHP72_RELDATE})
_PHP_VERSION_72_INSTALLED=	yes
_PHP_INSTALLED=			yes
.elif exists(${LOCALBASE}/lib/php/${PHP71_RELDATE})
_PHP_VERSION_71_INSTALLED=	yes
_PHP_INSTALLED=			yes
.elif exists(${LOCALBASE}/lib/php/${PHP56_RELDATE})
_PHP_VERSION_56_INSTALLED=	yes
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
.for pv in ${_PHP_VERSIONS_ACCEPTED}
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

# Major version
PKG_PHP_MAJOR_VERS:=	${_PHP_VERSION:C/^([0-9]).*/\1/}

PHP_CHECK_INSTALLED?=	Yes

# if installed PHP isn't compatible with required PHP, bail out
.if empty(PHP_CHECK_INSTALLED:M[nN][oO])
.if defined(_PHP_INSTALLED) && !defined(_PHP_VERSION_${_PHP_VERSION}_INSTALLED)
PKG_FAIL_REASON+=	"Package accepts ${PKG_PHP}, but different version is installed"
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
.if ${_PHP_VERSION} == "56"
PHPPKGSRCDIR=		../../lang/php56
PHP_VERSION=		${PHP56_VERSION}
PHP_INITIAL_TEENY=	3
PHP_PKG_PREFIX=		php56
PHP_EXTENSION_DIR=	lib/php/${PHP56_RELDATE}
.elif ${_PHP_VERSION} == "71"
PHPPKGSRCDIR=		../../lang/php71
PHP_VERSION=		${PHP71_VERSION}
PHP_INITIAL_TEENY=	0
PHP_PKG_PREFIX=		php71
PHP_EXTENSION_DIR=	lib/php/${PHP71_RELDATE}
.elif ${_PHP_VERSION} == "72"
PHPPKGSRCDIR=		../../lang/php72
PHP_VERSION=		${PHP72_VERSION}
PHP_INITIAL_TEENY=	0
PHP_PKG_PREFIX=		php72
PHP_EXTENSION_DIR=	lib/php/${PHP72_RELDATE}
.elif ${_PHP_VERSION} == "73"
PHPPKGSRCDIR=		../../lang/php73
PHP_VERSION=		${PHP73_VERSION}
PHP_INITIAL_TEENY=	0
PHP_PKG_PREFIX=		php73
PHP_EXTENSION_DIR=	lib/php/${PHP73_RELDATE}
.else
# force an error
PKG_FAIL_REASON+=	"${PKG_PHP} is not a valid package"
.endif

_PHP_VER_MAJOR=		${PHP_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\1/}
_PHP_VER_MINOR=		${PHP_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\2/}

PHP_BASE_VERS=	${_PHP_VER_MAJOR}.${_PHP_VER_MINOR}.${PHP_INITIAL_TEENY}

#
# check installed version aginst required:
#
.if !empty(PHP_CHECK_INSTALLED:M[nN][oO])
.if defined(_PHP_VERSION_INSTALLED) && ${_PHP_VERSION} != ${_PHP_VERSION_INSTALLED}
PKG_FAIL_REASON+=	"${PKGBASE} requires ${PKG_PHP}, but php-${_PHP_VERSION_INSTALLED} is already installed."
.endif
.endif

.endif	# PHPVERSION_MK
