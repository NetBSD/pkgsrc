# $NetBSD: builtin.mk,v 1.20 2023/01/16 08:17:30 adam Exp $

BUILTIN_PKG:=	libpcap

.include "../../mk/bsd.fast.prefs.mk"

BUILTIN_FIND_HEADERS_VAR:=		H_LIBPCAP
BUILTIN_FIND_HEADERS.H_LIBPCAP=		pcap/pcap.h
BUILTIN_FIND_HEADERS.H_LIBPCAP+=	pcap.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.libpcap)
IS_BUILTIN.libpcap=	no
.  if empty(H_LIBPCAP:M__nonexistent__) && empty(H_LIBPCAP:M${LOCALBASE}/*)
IS_BUILTIN.libpcap=	yes
.  endif
.endif
MAKEVARS+=		IS_BUILTIN.libpcap

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.libpcap) && \
    ${IS_BUILTIN.libpcap:tl} == yes && \
    empty(H_LIBPCAP:M__nonexistent__)
_BLTN_PCAP_111!=	\
	${GREP} -c PCAP_NETMASK_UNKNOWN ${H_LIBPCAP} || ${TRUE}
_BLTN_PCAP_100!=	\
	${GREP} -c pcap_offline_filter ${H_LIBPCAP} || ${TRUE}
# libpcap>=0.9.3: pcap_setdirection added (don't use pcap_inject, this
#  was hacked into the NetBSD version of 0.8.3)
_BLTN_PCAP_093!=	\
	${GREP} -c pcap_setdirection ${H_LIBPCAP} || ${TRUE}
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

.  if ${_BLTN_PCAP_111} == "1"
BUILTIN_VERSION.libpcap=	1.1.1
.  elif ${_BLTN_PCAP_100} == "1"
BUILTIN_VERSION.libpcap=	1.0.0
.  elif ${_BLTN_PCAP_093} == "1"
BUILTIN_VERSION.libpcap=	0.9.3nb1
.  elif ${_BLTN_PCAP_083} == "1"
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
BUILTIN_PKG.libpcap=		libpcap-${BUILTIN_VERSION.libpcap}
.endif
MAKEVARS+=			BUILTIN_PKG.libpcap

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
        ${IS_BUILTIN.libpcap:tl} == yes
USE_BUILTIN.libpcap=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.libpcap}
.        if ${USE_BUILTIN.libpcap:tl} == yes
USE_BUILTIN.libpcap!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.libpcap}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.libpcap
.endif
MAKEVARS+=		USE_BUILTIN.libpcap
