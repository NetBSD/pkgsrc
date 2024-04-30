# $NetBSD: options.mk,v 1.16 2024/04/30 10:38:15 wiz Exp $

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
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
.include "../../lang/python/versioned_dependencies.mk"
.endif

###
### Add in TeX support for psdump() and/or pdfdump()
###
.if !empty(PKG_OPTIONS:Mscapy-pyx)
DEPENDS+=	${PYPKGPREFIX}-X-[0-9]*:../../textproc/py-X
.endif

### TODO: matplotlib is another optional dependency
