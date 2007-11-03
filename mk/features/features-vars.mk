# $NetBSD: features-vars.mk,v 1.9 2007/11/03 11:50:18 rillig Exp $
#
# This file is included by bsd.prefs.mk.
#
# Package-settable variables:
#
# USE_FEATURES
#	Lists the system features required by the package.
#
#	Possible:
#	* err: The functions err, verr, errx, verrx.
#	* warn: The functions warn, vwarn, warnx, vwarnx.
#	* fts_close, ftp_open, fts_read, fts_set: Functions
#	  for filesystem traversal.
#	* getopt_long: The GNU version of getopt.
#	* getprogname, setprogname
#	* glob
#	* regcomp
#	* snprintf, vsnprintf
#	* utimes
#	* nbcompat: All of the above.
#
#	Default value: undefined
#
# Variables defined by this file:
#
# MISSING_FEATURES
#	The features listed in USE_FEATURES that are missing on the
#	current system.  Also includes "inet6" if the system doesn't
#	support IPv6.
#
# Keywords: feature features
#

_VARGROUPS+=		features
_USER_VARS.features=	# none
_PKG_VARS.features=	USE_FEATURES
_SYS_VARS.features=	MISSING_FEATURES

MISSING_FEATURES=	# empty

#
#	Handle "inet6" feature specially -- we always add it to
#	MISSING_FEATURES if the operating system doesn't support IPv6,
#	regardless of whether or not "inet6" is a requested feature
#	in USE_FEATURES.
#
.if defined(_OPSYS_HAS_INET6) && !empty(_OPSYS_HAS_INET6:M[nN][oO])
MISSING_FEATURES+=	inet6
.endif

.for _feature_ in err warn
.  if defined(USE_FEATURES) && !empty(USE_FEATURES:M${_feature_})
.    if (${OPSYS} != NetBSD) && (${OPSYS} != FreeBSD) && (${OPSYS} != DragonFly)
MISSING_FEATURES+=	${_feature_}
.    endif
.  endif
.endfor

.for _feature_ in fts_close fts_open fts_read fts_set
.  if defined(USE_FEATURES) && !empty(USE_FEATURES:M${_feature_})
.    if !exists(/usr/include/fts.h)
MISSING_FEATURES+=	${_feature_}
.    endif
.  endif
.endfor

.for _feature_ in getopt_long
.  if defined(USE_FEATURES) && !empty(USE_FEATURES:M${_feature_})
.    if !exists(/usr/include/getopt.h)
MISSING_FEATURES+=	${_feature_}
.    endif
.  endif
.endfor

.for _feature_ in getprogname setprogname
.  if defined(USE_FEATURES) && !empty(USE_FEATURES:M${_feature_})
.    if (${OPSYS} != NetBSD) && (${OPSYS} != FreeBSD) && (${OPSYS} != DragonFly)
MISSING_FEATURES+=	${_feature_}
.    endif
.  endif
.endfor

.for _feature_ in glob
.  if defined(USE_FEATURES) && !empty(USE_FEATURES:M${_feature_})
.    if !exists(/usr/include/glob.h)
MISSING_FEATURES+=	${_feature_}
.    endif
.  endif
.endfor

.for _feature_ in regcomp
.  if defined(USE_FEATURES) && !empty(USE_FEATURES:M${_feature_})
.    if !exists(/usr/include/regex.h)
MISSING_FEATURES+=	${_feature_}
.    endif
.  endif
.endfor

.for _feature_ in snprintf vsnprintf
.  if defined(USE_FEATURES) && !empty(USE_FEATURES:M${_feature_})
.    if ${OPSYS} == "IRIX"
MISSING_FEATURES+=	${_feature_}
.    endif
.  endif
.endfor

.for _feature_ in utimes
.  if defined(USE_FEATURES) && !empty(USE_FEATURES:M${_feature_})
.    if ${OPSYS} == "Interix"
MISSING_FEATURES+=	${_feature_}
.    endif
.  endif
.endfor

.if defined(USE_FEATURES) && !empty(USE_FEATURES:Mnbcompat)
MISSING_FEATURES+=	nbcompat
.endif
