# $NetBSD: options.mk,v 1.1 2007/01/03 15:02:51 adrianp Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.scapy

PKG_SUPPORTED_OPTIONS=	scapy-crypto gnuplot scapy-pyx

.include "../../mk/bsd.options.mk"

###
### Add in crypto support for WEP operations
###
.if !empty(PKG_OPTIONS:Mscapy-crypto)
.	include "../../security/py-amkCrypto/buildlink3.mk"
.endif

###
### Add in gnuplot support for plotting
###
.if !empty(PKG_OPTIONS:Mgnuplot)
DEPENDS+=	${PYPKGPREFIX}-gnuplot-[0-9]*:../../graphics/py-gnuplot
.endif

###
### Add in TeX support for psdump() and/or pdfdump()
###
.if !empty(PKG_OPTIONS:Mscapy-pyx)
DEPENDS+=	${PYPKGPREFIX}-X-[0-9]*:../../textproc/py-X
.endif
