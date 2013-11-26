# $NetBSD: features-vars.mk,v 1.21 2013/11/26 07:04:55 obache Exp $
#
# The platforms that are supported by pkgsrc differ in the amount of
# functions they provide in the C library (libc). Functions that are
# typically available on NetBSD are provided in the libnbcompat package.
#
# This file defines a set of "features" that some packages require.
# Whenever a package makes use of them, it should list the features in
# the USE_FEATURES variable. (It serves a similar purpose as USE_TOOLS.)
#
# The *.c files that use the features must be patched a little. When
# there are missing features, the C preprocessor macro HAVE_NBCOMPAT_H
# will be defined to 1. In this case, the headers from the nbcompat
# directory must be included.
#
# === Example ===
#
# In the package Makefile:
#
#	USE_FEATURES=		err
#
# In the C files using the err*() or warn*() functions:
#
#	#if defined(HAVE_NBCOMPAT_H)
#	#include <nbcompat/config.h>	/* needed for the other headers */
#	#include <nbcompat/cdefs.h>	/* needed for the other headers */
#	#include <nbcompat/err.h>
#	#else
#	#include <err.h>
#	#endif
#
# === Package-settable variables ===
#
# USE_FEATURES
#	Lists the system features required by the package.
#
#	Possible:
#	* asprintf: The functions asprintf and vasprintf.
#	* cdefs: The header sys/cdefs.h.
#	* err: The functions err, verr, errx, verrx.
#	* warn: The functions warn, vwarn, warnx, vwarnx.
#	* fts_close, fts_open, fts_read, fts_set: Functions
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
# === Variables defined by this file ===
#
# MISSING_FEATURES
#	The features listed in USE_FEATURES that are missing on the
#	current system.  Also includes "inet6" if the system doesn't
#	support IPv6.
#
# Keywords: feature features asprintf vasprintf cdefs err errx warn warnx
# Keywords: fts fts_open fts_read fts_set fts_close getopt_long
# Keywords: getprogname setprogname glob regcomp setenv snprintf vsnprintf
# Keywords: utimes libnbcompat nbcompat

_VARGROUPS+=		features
_USER_VARS.features=	# none
_PKG_VARS.features=	USE_FEATURES
_SYS_VARS.features=	MISSING_FEATURES

MISSING_FEATURES=	# empty
USE_FEATURES?=		# none

#
#	Handle "inet6" feature specially -- we always add it to
#	MISSING_FEATURES if the operating system doesn't support IPv6,
#	regardless of whether or not "inet6" is a requested feature
#	in USE_FEATURES.
#
.if defined(_OPSYS_HAS_INET6) && !empty(_OPSYS_HAS_INET6:M[nN][oO])
MISSING_FEATURES+=	inet6
.endif

.for f in ${_OPSYS_MISSING_FEATURES}
.  if !empty(USE_FEATURES:M${f})
MISSING_FEATURES+=	${f}
.  endif
.endfor

.if !empty(USE_FEATURES:Mcdefs)
BUILTIN_FIND_HEADERS_VAR:=			_FEATURES_SYS_CDEFS_H
BUILTIN_FIND_HEADERS._FEATURES_SYS_CDEFS_H=	sys/cdefs.h
.include "../../mk/buildlink3/find-headers.mk"
.  if !empty(_FEATURES_SYS_CDEFS_H:M__nonexistent__)
MISSING_FEATURES+=	cdefs
.  endif
.endif

.for _feature_ in err warn
.  if !empty(USE_FEATURES:M${_feature_})
.    if (${OPSYS} != NetBSD) && (${OPSYS} != FreeBSD) && (${OPSYS} != DragonFly)
MISSING_FEATURES+=	${_feature_}
.    endif
.  endif
.endfor

.for _feature_ in fts_close fts_open fts_read fts_set
.  if !empty(USE_FEATURES:M${_feature_})
.    ifndef (_FEATURES_FTS_H)
BUILTIN_FIND_HEADERS_VAR:=		_FEATURES_FTS_H
BUILTIN_FIND_HEADERS._FEATURES_FTS_H=	fts.h
.include "../../mk/buildlink3/find-headers.mk"
.    endif
.    if !empty(_FEATURES_FTS_H:M__nonexistent__)
MISSING_FEATURES+=	${_feature_}
.    endif
.  endif
.endfor

.for _feature_ in getopt_long
.  if !empty(USE_FEATURES:M${_feature_})
.    ifndef (_FEATURES_GETOPT_LONG)
BUILTIN_FIND_HEADERS_VAR:=			_FEATURES_GETOPT_LONG
BUILTIN_FIND_HEADERS._FEATURES_GETOPT_LONG=	getopt.h
BUILTIN_FIND_GREP._FEATURES_GETOPT_LONG=	getopt_long
.include "../../mk/buildlink3/find-headers.mk"
.    endif
.    if !empty(_FEATURES_GETOPT_LONG:M_nonexistent__)
MISSING_FEATURES+=	${_feature_}
.    endif
.  endif
.endfor

.for _feature_ in getprogname setprogname
.  if !empty(USE_FEATURES:M${_feature_})
.    if (${OPSYS} != NetBSD) && (${OPSYS} != FreeBSD) && (${OPSYS} != DragonFly)
MISSING_FEATURES+=	${_feature_}
.    endif
.  endif
.endfor

.for _feature_ in glob
.  if !empty(USE_FEATURES:M${_feature_})
.    ifndef (_FEATURES_GLOB_H)
BUILTIN_FIND_HEADERS_VAR:=		_FEATURES_GLOB_H
BUILTIN_FIND_HEADERS._FEATURES_GLOB_H=	glob.h
.include "../../mk/buildlink3/find-headers.mk"
.    endif
.    if !empty(_FEATURES_GLOB_H:M__nonexistent__)
MISSING_FEATURES+=	${_feature_}
.    endif
.  endif
.endfor

.for _feature_ in regcomp
.  if !empty(USE_FEATURES:M${_feature_})
.    ifndef (_FEATURES_REGEX_H)
BUILTIN_FIND_HEADERS_VAR:=		_FEATURES_REGEX_H
BUILTIN_FIND_HEADERS._FEATURES_REGEX_H=	regex.h
.include "../../mk/buildlink3/find-headers.mk"
.    endif
.    if !empty(_FEATURES_REGEX_H:M__nonexistent__)
MISSING_FEATURES+=	${_feature_}
.    endif
.  endif
.endfor

.for _feature_ in setenv
.  if !empty(USE_FEATURES:M${_feature_})
.    if !empty(MACHINE_PLATFORM:MHPUX-11.11-hppa) # XXX too narrow?
MISSING_FEATURES+=	${_feature_}
.   endif
.  endif
.endfor

.for _feature_ in snprintf vsnprintf
.  if !empty(USE_FEATURES:M${_feature_})
.    if ${OPSYS} == "IRIX" || !empty(MACHINE_PLATFORM:MHPUX-11.11-hppa)
MISSING_FEATURES+=	${_feature_}
.    endif
.  endif
.endfor

.for _feature_ in utimes
.  if !empty(USE_FEATURES:M${_feature_})
.    if ${OPSYS} == "Interix"
MISSING_FEATURES+=	${_feature_}
.    endif
.  endif
.endfor

.if !empty(USE_FEATURES:Mnbcompat)
MISSING_FEATURES+=	nbcompat
.endif
