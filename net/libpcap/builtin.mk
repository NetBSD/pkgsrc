# $NetBSD: builtin.mk,v 1.1 2004/03/10 17:57:14 jlam Exp $

.if !defined(IS_BUILTIN.libpcap)
IS_BUILTIN.libpcap=	no
.  if exists(/usr/include/pcap.h)
IS_BUILTIN.libpcap=	yes
.  endif
.endif

CHECK_BUILTIN.libpcap?=	no
.if !empty(CHECK_BUILTIN.libpcap:M[yY][eE][sS])
USE_BUILTIN.libpcap=	yes
.endif

USE_BUILTIN.libpcap?=	${IS_BUILTIN.libpcap}
