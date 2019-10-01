# $NetBSD: options.mk,v 1.3 2019/10/01 13:49:58 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.znc
PKG_SUPPORTED_OPTIONS=	inet6 nls perl python sasl-cyrus tcl
PKG_SUGGESTED_OPTIONS=	inet6 nls

PKG_OPTIONS_LEGACY_OPTS+=	sasl:sasl-cyrus

.include "../../mk/bsd.options.mk"

# IPv6 support
.if !empty(PKG_OPTIONS:Minet6)
CMAKE_ARGS+=	-DWANT_IPV6=ON
.else
CMAKE_ARGS+=	-DWANT_IPV6=OFF
.endif

# Native Language support
.if !empty(PKG_OPTIONS:Mnls)
USE_TOOLS+=	msgfmt
PLIST_SRC+=	PLIST.nls
CMAKE_ARGS+=	-DWANT_I18N=ON
CMAKE_ARGS+=	-DWANT_ICU=ON
.  include "../../devel/boost-libs/buildlink3.mk"
.  include "../../textproc/icu/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWANT_I18N=OFF
CMAKE_ARGS+=	-DWANT_ICU=OFF
.endif

# Perl support
.if !empty(PKG_OPTIONS:Mperl)
.  include "../../lang/perl5/buildlink3.mk"
CMAKE_ARGS+=	-DWANT_PERL=ON
USE_TOOLS+=	perl
PLIST_SRC+=	PLIST.perl
.else
CMAKE_ARGS+=	-DWANT_PERL=OFF
.endif

# TCL option
.if !empty(PKG_OPTIONS:Mtcl)
.  include "../../lang/tcl/buildlink3.mk"
CMAKE_ARGS+=	-DWANT_TCL=ON
PLIST_SRC+=	PLIST.tcl
.else
CMAKE_ARGS+=	-DWANT_TCL=OFF
.endif

# Python support
.if !empty(PKG_OPTIONS:Mpython)
PYTHON_VERSIONS_INCOMPATIBLE=	27
.  include "../../lang/python/extension.mk"
CMAKE_ARGS+=	-DWANT_PYTHON=ON
CMAKE_ARGS+=	-DWANT_PYTHON_VERSION=python-${PYVERSSUFFIX}
PLIST_SRC+=	PLIST.python
.else
CMAKE_ARGS+=	-DWANT_PYTHON=OFF
.endif

# Cyrus SASL support
.if !empty(PKG_OPTIONS:Msasl-cyrus)
.include "../../security/cyrus-sasl/buildlink3.mk"
CMAKE_ARGS+=	-DWANT_CYRUS=ON
PLIST_SRC+=	PLIST.cyrus
.else
CMAKE_ARGS+=	-DWANT_CYRUS=OFF
.endif
