# $NetBSD: builtin.mk,v 1.9 2005/01/11 21:19:24 xtraeme Exp $

_LIBPCAP_PKGSRC_PKGNAME=	libpcap-0.8.3
_LIBPCAP_PCAP_H=		/usr/include/pcap.h

.if !defined(IS_BUILTIN.libpcap)
IS_BUILTIN.libpcap=	no
.  if exists(${_LIBPCAP_PCAP_H})
IS_BUILTIN.libpcap=	yes

# libpcap>=0.8.3: MODE_MON added
_PCAP_083!=		\
	${GREP} -c MODE_MON ${_LIBPCAP_PCAP_H} || ${TRUE}
# libpcap>=0.8.1: pcap_get_selectable_fd added
_PCAP_081!=		\
	${GREP} -c pcap_get_selectable_fd ${_LIBPCAP_PCAP_H} || ${TRUE}
# libpcap>=0.8.0: pcap_datalink_val_to_description added
_PCAP_080!=		\
	${GREP} -c pcap_datalink_val_to_description	\
		${_LIBPCAP_PCAP_H} || ${TRUE}
# libpcap>=0.7.0: pcap_setnonblock added
_PCAP_070!=		\
	${GREP} -c pcap_setnonblock ${_LIBPCAP_PCAP_H} || ${TRUE}
# libpcap>=0.6.0: prototype change for pcap_freecode
_PCAP_060!=		\
	${GREP} -c pcap_freecode.struct.bpf_program	\
		${_LIBPCAP_PCAP_H} || ${TRUE}
# libpcap>=0.5.0: pcap_compile_nopcap added
_PCAP_050!=		\
	${GREP} -c pcap_compile_nopcap ${_LIBPCAP_PCAP_H} || ${TRUE}

.if ${_PCAP_083} == "1"
BUILTIN_PKG.libpcap=	libpcap-0.8.3
.elif ${_PCAP_081} == "1"
BUILTIN_PKG.libpcap=	libpcap-0.8.1
.elif ${_PCAP_080} == "1"
BUILTIN_PKG.libpcap=	libpcap-0.8.0
.elif ${_PCAP_070} == "1"
BUILTIN_PKG.libpcap=	libpcap-0.7.0
.elif ${_PCAP_060} == "1"
BUILTIN_PKG.libpcap=	libpcap-0.6.0
.elif ${_PCAP_050} == "1"
BUILTIN_PKG.libpcap=	libpcap-0.5.0
.else
BUILTIN_PKG.libpcap=	libpcap-0.4.0
.endif

.endif  # exists({_LIBPCAP_PCAP_H})

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
.endif  # IS_BUILTIN.libpcap
