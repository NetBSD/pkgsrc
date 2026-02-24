# $NetBSD: options.mk,v 1.6 2026/02/24 14:47:18 triaxx Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.znc
PKG_SUPPORTED_OPTIONS=	icu inet6 nls perl python sasl-cyrus tcl
PKG_SUGGESTED_OPTIONS=	icu inet6 nls

PKG_OPTIONS_LEGACY_OPTS+=	sasl:sasl-cyrus

.include "../../mk/bsd.options.mk"

# IPv6 support
.if !empty(PKG_OPTIONS:Minet6)
CMAKE_CONFIGURE_ARGS+=	-DWANT_IPV6=ON
.else
CMAKE_CONFIGURE_ARGS+=	-DWANT_IPV6=OFF
.endif

# Charset support
.if !empty(PKG_OPTIONS:Micu)
CMAKE_CONFIGURE_ARGS+=	-DWANT_ICU=ON
.  include "../../textproc/icu/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DWANT_ICU=OFF
.endif

# Native Language support
.if !empty(PKG_OPTIONS:Mnls)
USE_TOOLS+=	msgfmt
PLIST_SRC+=	PLIST.nls
CMAKE_CONFIGURE_ARGS+=	-DWANT_I18N=ON
BUILDLINK_API_DEPENDS.boost-libs+=	boost-libs>=1.70
.  include "../../devel/boost-libs/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DWANT_I18N=OFF
.endif

# Perl support
.if !empty(PKG_OPTIONS:Mperl)
.  include "../../lang/perl5/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DWANT_PERL=ON
USE_TOOLS+=	perl
PLIST_SRC+=	PLIST.perl
.else
CMAKE_CONFIGURE_ARGS+=	-DWANT_PERL=OFF
.endif

# TCL option
.if !empty(PKG_OPTIONS:Mtcl)
.  include "../../lang/tcl/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DWANT_TCL=ON
PLIST_SRC+=	PLIST.tcl
.else
CMAKE_CONFIGURE_ARGS+=	-DWANT_TCL=OFF
.endif

# Python support
.if !empty(PKG_OPTIONS:Mpython)
PYTHON_VERSIONS_INCOMPATIBLE=	27
.  include "../../lang/python/extension.mk"
CMAKE_CONFIGURE_ARGS+=	-DWANT_PYTHON=ON
CMAKE_CONFIGURE_ARGS+=	-DWANT_PYTHON_VERSION=python-${PYVERSSUFFIX}
PLIST_SRC+=	PLIST.python
.else
CMAKE_CONFIGURE_ARGS+=	-DWANT_PYTHON=OFF
.endif

# Cyrus SASL support
.if !empty(PKG_OPTIONS:Msasl-cyrus)
.include "../../security/cyrus-sasl/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DWANT_CYRUS=ON
PLIST_SRC+=	PLIST.cyrus
.else
CMAKE_CONFIGURE_ARGS+=	-DWANT_CYRUS=OFF
.endif
