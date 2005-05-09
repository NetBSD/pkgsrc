# $NetBSD: phpversion.mk,v 1.3 2005/05/09 19:24:46 jdolecek Exp $
# PHP wrapper, for module builds

.if !defined(PHPVERSION_MK)
PHPVERSION_MK=	defined

.include "../../mk/bsd.prefs.mk"

PHP_VERSION_DEFAULT?=		4
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
PHPPKGSRCDIR=	../../www/php4
.elif ${_PHP_VERSION} == "5"
PHPPKGSRCDIR=	../../lang/php5
.else
# force an error
PKG_SKIP_REASON+=	"${PKG_PHP} is not a valid package"
.endif

.endif	# PHPVERSION_MK
