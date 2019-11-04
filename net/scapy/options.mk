# $NetBSD: options.mk,v 1.12 2019/11/04 05:48:26 gutteridge Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.scapy

PKG_SUPPORTED_OPTIONS=	libpcap scapy-crypto gnuplot scapy-pyx
PKG_SUGGESTED_OPTIONS=	libpcap

.include "../../mk/bsd.options.mk"

###
### Ensure libpcap is available in the environment. (In many cases, it
### should be part of a base installation. It is most essential for
### SunOS support, where it's depended upon more than for other OSes.)
###
.if !empty(PKG_OPTIONS:Mlibpcap)
.include "../../net/libpcap/buildlink3.mk"
.endif

###
### Add in crypto support for WEP operations
###
.if !empty(PKG_OPTIONS:Mscapy-crypto)
DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography
.endif

###
### Add in gnuplot support for plotting
###
.if !empty(PKG_OPTIONS:Mgnuplot)
DEPENDS+=	${PYPKGPREFIX}-gnuplot-[0-9]*:../../graphics/py-gnuplot
PYTHON_VERSIONS_ACCEPTED= 27 # py-gnuplot
.endif

###
### Add in TeX support for psdump() and/or pdfdump()
###
.if !empty(PKG_OPTIONS:Mscapy-pyx)
PYTHON_VERSIONED_DEPENDENCIES=	X
.include "../../lang/python/versioned_dependencies.mk"
.endif
