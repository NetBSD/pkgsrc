# $NetBSD: options.mk,v 1.2 2022/07/04 08:13:37 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.openipmi
# python: distutils is deprecated
# https://sourceforge.net/p/openipmi/feature-requests/10/
PKG_SUPPORTED_OPTIONS=		perl snmp swig
PKG_SUGGESTED_OPTIONS=		perl snmp swig

PLIST_VARS+=			perl python

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mperl)
CONFIGURE_ARGS+=	--with-perl=${PERl5}
.include "../../lang/perl5/buildlink3.mk"
PLIST.perl=		yes
.else
CONFIGURE_ARGS+=	--with-perl=no
.endif

# uses distutils, which is deprecated
.if !empty(PKG_OPTIONS:Mpython)
CONFIGURE_ARGS+=	--with-python=${PYTHONBIN}
.include "../../lang/python/pyversion.mk"
PLIST.python=		yes
PLIST_SUBST+=		PYSITELIB=${PYSITELIB}
.else
CONFIGURE_ARGS+=	--with-python=no
.endif

.if !empty(PKG_OPTIONS:Msnmp)
CONFIGURE_ARGS+=	--with-ucdsnmp=${PREFIX}
.include "../../net/net-snmp/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-ucdsnmp=no
.endif

.if !empty(PKG_OPTIONS:Mswig)
CONFIGURE_ARGS+=	--with-swig=${PREFIX}/bin/swig3.0
.include "../../devel/swig3/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-swig=no
.endif
