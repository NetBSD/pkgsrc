# $NetBSD: options.mk,v 1.13 2022/01/25 01:44:22 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.scapy

PKG_SUPPORTED_OPTIONS=	libpcap scapy-crypto scapy-pyx
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
### Add in TeX support for psdump() and/or pdfdump()
###
.if !empty(PKG_OPTIONS:Mscapy-pyx)
PYTHON_VERSIONED_DEPENDENCIES=	X
.include "../../lang/python/versioned_dependencies.mk"
.endif
