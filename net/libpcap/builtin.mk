# $NetBSD: builtin.mk,v 1.10 2005/06/01 18:03:07 jlam Exp $

BUILTIN_PKG:=	libpcap

BUILTIN_FIND_FILES_VAR:=	H_LIBPCAP
BUILTIN_FIND_FILES.H_LIBPCAP=	/usr/include/pcap.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.libpcap)
IS_BUILTIN.libpcap=	no
.  if empty(H_LIBPCAP:M${LOCALBASE}/*) && exists(${H_LIBPCAP})
IS_BUILTIN.libpcap=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.libpcap

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.libpcap) && \
    !empty(IS_BUILTIN.libpcap:M[yY][eE][sS]) && \
    exists(${H_LIBPCAP})
# libpcap>=0.8.3: MODE_MON added
_BLTN_PCAP_083!=	\
	${GREP} -c MODE_MON ${H_LIBPCAP} || ${TRUE}
# libpcap>=0.8.1: pcap_get_selectable_fd added
_BLTN_PCAP_081!=	\
	${GREP} -c pcap_get_selectable_fd ${H_LIBPCAP} || ${TRUE}
# libpcap>=0.8.0: pcap_datalink_val_to_description added
_BLTN_PCAP_080!=	\
	${GREP} -c pcap_datalink_val_to_description ${H_LIBPCAP} || ${TRUE}
# libpcap>=0.7.0: pcap_setnonblock added
_BLTN_PCAP_070!=	\
	${GREP} -c pcap_setnonblock ${H_LIBPCAP} || ${TRUE}
# libpcap>=0.6.0: prototype change for pcap_freecode
_BLTN_PCAP_060!=	\
	${GREP} -c pcap_freecode.struct.bpf_program ${H_LIBPCAP} || ${TRUE}
# libpcap>=0.5.0: pcap_compile_nopcap added
_BLTN_PCAP_050!=	\
	${GREP} -c pcap_compile_nopcap ${H_LIBPCAP} || ${TRUE}

.  if ${_BLTN_PCAP_083} == "1"
BUILTIN_VERSION.libpcap=	0.8.3
.  elif ${_BLTN_PCAP_081} == "1"
BUILTIN_VERSION.libpcap=	0.8.1
.  elif ${_BLTN_PCAP_080} == "1"
BUILTIN_VERSION.libpcap=	0.8.0
.  elif ${_BLTN_PCAP_070} == "1"
BUILTIN_VERSION.libpcap=	0.7.0
.  elif ${_BLTN_PCAP_060} == "1"
BUILTIN_VERSION.libpcap=	0.6.0
.  elif ${_BLTN_PCAP_050} == "1"
BUILTIN_VERSION.libpcap=	0.5.0
.  else
BUILTIN_VERSION.libpcap=	0.4.0
.  endif
BUILTIN_PKG.libpcap=	libpcap-${BUILTIN_VERSION.libpcap}
.endif
MAKEVARS+=	BUILTIN_PKG.libpcap

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.libpcap)
.  if ${PREFER.libpcap} == "pkgsrc"
USE_BUILTIN.libpcap=	no
.  else
USE_BUILTIN.libpcap=	${IS_BUILTIN.libpcap}
.    if defined(BUILTIN_PKG.libpcap) && \
        !empty(IS_BUILTIN.libpcap:M[yY][eE][sS])
USE_BUILTIN.libpcap=	yes
.      for _dep_ in ${BUILDLINK_DEPENDS.libpcap}
.        if !empty(USE_BUILTIN.libpcap:M[yY][eE][sS])
USE_BUILTIN.libpcap!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.libpcap:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.libpcap
.endif
MAKEVARS+=	USE_BUILTIN.libpcap
