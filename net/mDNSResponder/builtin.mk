# $NetBSD: builtin.mk,v 1.12 2026/01/11 18:23:03 wiz Exp $

BUILTIN_PKG:=	mDNSResponder

BUILTIN_FIND_HEADERS_VAR:=	H_DNSSD
BUILTIN_FIND_HEADERS.H_DNSSD=	dns_sd.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.mDNSResponder)
IS_BUILTIN.mDNSResponder=	no
.  if empty(H_DNSSD:M__nonexistent__)
IS_BUILTIN.mDNSResponder=	yes
.  endif
.endif	# IS_BUILTIN.mDNSResponder
MAKEVARS+=			IS_BUILTIN.mDNSResponder

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.mDNSResponder) && \
    !empty(IS_BUILTIN.mDNSResponder:M[yY][eE][sS]) && \
    empty(H_DNSSD:M__nonexistent__)
_DNSSD_VERSION!=${SED} -En 's,\#define[  ]+_DNS_SD_H[    ]+([0-9]+),\1,p' ${H_DNSSD}
.  if ${_DNSSD_VERSION} == "2120100"
BUILTIN_VERSION.mDNSResponder=	212.1
.  elif ${_DNSSD_VERSION} == "2140302"
BUILTIN_VERSION.mDNSResponder=	214.3.2
.  elif ${_DNSSD_VERSION} == "2581400"
BUILTIN_VERSION.mDNSResponder=	258.14
.  elif ${_DNSSD_VERSION} == "3200500"
BUILTIN_VERSION.mDNSResponder=	320.5
.  elif ${_DNSSD_VERSION} == "3201600"
BUILTIN_VERSION.mDNSResponder=	320.16
.  elif ${_DNSSD_VERSION} == "8780101"
BUILTIN_VERSION.mDNSResponder=	878.1.1
.  elif ${_DNSSD_VERSION} == "8783004"
BUILTIN_VERSION.mDNSResponder=	878.30.4
.  elif ${_DNSSD_VERSION} == "16610000"
BUILTIN_VERSION.mDNSResponder=	2559.1.1
.  else
BUILTIN_VERSION.mDNSResponder=	0 #unknown
.  endif
BUILTIN_PKG.mDNSResponder=	mDNSResponder-${BUILTIN_VERSION.mDNSResponder}
.endif

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.mDNSResponder)
.  if ${PREFER.mDNSResponder} == "pkgsrc"
USE_BUILTIN.mDNSResponder=	no
.  else
USE_BUILTIN.mDNSResponder=	${IS_BUILTIN.mDNSResponder}
.    if defined(BUILTIN_PKG.mDNSResponder) && \
        !empty(IS_BUILTIN.mDNSResponder:M[yY][eE][sS])
USE_BUILTIN.mDNSResponder=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.mDNSResponder}
.        if !empty(USE_BUILTIN.mDNSResponder:M[yY][eE][sS])
USE_BUILTIN.mDNSResponder!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.mDNSResponder:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.mDNSResponder
.endif
MAKEVARS+=			USE_BUILTIN.mDNSResponder
