# $NetBSD: phpversion.mk,v 1.6 2007/06/18 07:21:09 rillig Exp $
#
# This file selects a PHP version, based on the user's preferences and
# the installed packages.
#
# === User-settable variables ===
#
# PHP_VERSION_DEFAULT
#	The PHP version to choose when more than one is acceptable to
#	the package.
#
#	Possible: 4 5
#	Default: 4
#
# === Package-settable variables ===
#
# PHP_VERSIONS_ACCEPTED
#	The PHP versions that are accepted by the package.
#
#	Possible: 4 5
#	Default: 4 5
#
# PHP_VERSION_REQD
#	If the package works only with a specific PHP version, this
#	variable can be used to force it.
#
#	Possible: (undefined) 4 5
#	Default: (undefined)
#
# === Variables defined by this file ===
#
# PKG_PHP_VERSION
#	The selected PHP version.
#
#	Possible: 4 5
#	Default: ${PHP_VERSION_DEFAULT}
#
# PKG_PHP
#	The same as ${PKG_PHP_VERSION}, prefixed with "PHP".
#	XXX: Why is this necessary?
#
# PHPPKGSRCDIR
#	The directory of the PHP implementation, relative to the
#	package directory.
#
#	Example: ../../lang/php5
#
# PHP_PKG_PREFIX
#	The prefix that is prepended to the package name.
#
#	Example: php5
#
# Keywords: php
#

.if !defined(PHPVERSION_MK)
PHPVERSION_MK=	defined

.include "../../mk/bsd.prefs.mk"

PHP_VERSION_DEFAULT?=		5
PHP_VERSIONS_ACCEPTED?=		4 5

# transform the list into individual variables
.for pv in ${PHP_VERSIONS_ACCEPTED}
_PHP_VERSION_${pv}_OK=	yes
.endfor

# check what is installed
.if exists(${LOCALBASE}/lib/php/20020429)
_PHP_VERSION_4_INSTALLED=	yes
.endif
.if exists(${LOCALBASE}/lib/php/20040412)
_PHP_VERSION_5_INSTALLED=	yes
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

# export some of internal variables
PKG_PHP_VERSION:=	${_PHP_VERSION}
PKG_PHP:=		PHP${_PHP_VERSION}

MESSAGE_SUBST+=		PKG_PHP_VERSION=${PKG_PHP_VERSION} \
			PKG_PHP=${PKG_PHP}
PLIST_SUBST+=		PKG_PHP_VERSION=${PKG_PHP_VERSION}

# force the selected PHP version for recursive builds
PHP_VERSION_REQD:=	${PKG_PHP_VERSION}

#
# set variables for the version we decided to use:
#
.if ${_PHP_VERSION} == "4"
PHPPKGSRCDIR=		../../www/php4
PHP_PKG_PREFIX=		php4
.elif ${_PHP_VERSION} == "5"
PHPPKGSRCDIR=		../../lang/php5
PHP_PKG_PREFIX=		php5
.else
# force an error
PKG_SKIP_REASON+=	"${PKG_PHP} is not a valid package"
.endif

.endif	# PHPVERSION_MK
