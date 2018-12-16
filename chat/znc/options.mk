# $NetBSD: options.mk,v 1.1 2018/12/16 02:05:23 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.znc
PKG_SUPPORTED_OPTIONS=	debug inet6 perl python sasl tcl
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

# Debug build
.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif

# IPv6 support
.if empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

# Perl support
.if !empty(PKG_OPTIONS:Mperl)
.include		"../../lang/perl5/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-perl
USE_TOOLS+=		perl
PLIST_SRC+=		PLIST.perl
.endif

# TCL option
.if !empty(PKG_OPTIONS:Mtcl)
.include		"../../lang/tcl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-tcl
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib
PLIST_SRC+=		PLIST.tcl
.endif

# Python support
.if !empty(PKG_OPTIONS:Mpython)
PYTHON_VERSIONS_INCOMPATIBLE=	27
.include		"../../lang/python/extension.mk"
CONFIGURE_ARGS+=	--enable-python=python-${PYVERSSUFFIX}
PLIST_SRC+=		PLIST.python
.endif

# Cyrus SASL support
.if !empty(PKG_OPTIONS:Msasl)
.include		"../../security/cyrus-sasl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-cyrus
PLIST_SRC+=		PLIST.cyrus
.endif
