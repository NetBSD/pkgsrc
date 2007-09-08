# $NetBSD: features-vars.mk,v 1.5 2007/09/08 05:06:40 jlam Exp $
#
# This file is include by bsd.prefs.mk.
#
# Package-settable variables:
#
# USE_FEATURES
#	Lists the system features required by the package.
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
.    if !empty(LOWER_OPSYS:Mirix5*)
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
