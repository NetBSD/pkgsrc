# $NetBSD: builtin.mk,v 1.3 2005/01/11 19:32:17 xtraeme Exp $

_LIBPCAP_H=	/usr/include/pcap.h

.if !defined(IS_BUILTIN.libpcap)
IS_BUILTIN.libpcap=	no
.  if exists(${_LIBPCAP_H})
IS_BUILTIN.libpcap!=							\
	if ${GREP} -q PCAP_VERSION_MAJOR ${_LIBPCAP_H}; then		\
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.    if !empty(IS_BUILTIN.libpcap:M[yY][eE][sS])
#
# Create an appropriate name for the built-in package distributed
# with the system.  This package name can be used to check against
# BUILDLINK_DEPENDS.<pkg> to see if we need to install the pkgsrc
# version or if the built-in one is sufficient.
#
.      if !defined(_LIPCAP_VERSION)
_LIBPCAP_VERSIONS=	0.8.3  0.7.2
_LIBPCAP_0.8.3=		NetBSD-2.99.9* NetBSD-2.99.1[0-9]*
_LIBPCAP_0.7=		NetBSD-1.[56]* NetBSD-2.0*
.        for _libpcap_version_ in ${_LIBPCAP_VERSIONS}
.          for _pattern_ in ${_LIBPCAP_${_libpcap_version_}}
.            if !empty(MACHINE_PLATFORM:M${_pattern_})
_LIBPCAP_VERSION?=	${_libpcap_version_}
.            endif
.          endfor
.        endfor
_LIBPCAP_VERSION?=	0.7.2
.      endif
BUILTIN_PKG.libpcap=	libpcap-${_LIBPCAP_VERSION}
MAKEFLAGS+=		BUILTIN_PKG.libpcap=${BUILTIN_PKG.libpcap}
.    endif
.  endif
MAKEFLAGS+=	IS_BUILTIN.libpcap=${IS_BUILTIN.libpcap}
.endif

.if !defined(USE_BUILTIN.libpcap)
USE_BUILTIN.libpcap?=	${IS_BUILTIN.libpcap}

.  if defined(BUILTIN_PKG.libpcap)
USE_BUILTIN.libpcap=	yes
.    for _depend_ in ${BUILDLINK_DEPENDS.libpcap}
.      if !empty(USE_BUILTIN.libpcap:M[yY][eE][sS])
USE_BUILTIN.libpcap!=	\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${BUILTIN_PKG.libpcap}; then \
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.      endif
.    endfor
.  endif
.endif	# USE_BUILTIN.libpcap

CHECK_BUILTIN.libpcap?=	no
.if !empty(CHECK_BUILTIN.libpcap:M[nN][oO])

.if !empty(USE_BUILTIN.libpcap:M[nN][oO])
BUILDLINK_DEPENDS.libpcap+=	libpcap>=0.8.3
.endif

.endif	# CHECK_BUILTIN.libpcap
