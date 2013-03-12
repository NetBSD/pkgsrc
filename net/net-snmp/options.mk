# $NetBSD: options.mk,v 1.15 2013/03/12 03:00:38 garbled Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.net-snmp
PKG_SUPPORTED_OPTIONS=		ssl snmp-unprived snmp-nokmem perl
PKG_SUGGESTED_OPTIONS=		perl

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "SunOS"
# net-snmp doesn't do IPv6 on Solaris
PKG_SUPPORTED_OPTIONS+=		inet6
PKG_SUGGESTED_OPTIONS+=		inet6
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		inet6 perl
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
PLIST.inet6=		yes
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openssl
.else
CONFIGURE_ARGS+=	--without-openssl
.endif

.if !empty(PKG_OPTIONS:Msnmp-nokmem)
CONFIGURE_ARGS+=	--without-kmem-usage
.endif

.if !empty(PKG_OPTIONS:Msnmp-unprived)
CONFIGURE_ARGS+=	--without-root-access
.endif

.if !empty(PKG_OPTIONS:Mperl)
# The self-test of Perl modules only works after installation because perl
# can't load the shared libraries from WRKSRC/
# Until this is fixed you can test them after installation by doing
# `make test TEST_TARGET=perltest'
TEST_TARGET=		test

PLIST.perl=		yes
USE_TOOLS+=		perl
PERL5_CONFIGURE=	no
PERL5_PACKLIST=		auto/Bundle/NetSNMP/.packlist
CONFIGURE_ARGS+=	--with-perl-modules=${MAKE_PARAMS:Q}
CONFIGURE_ENV+=		PERLPROG=${PERL5:Q}
.include "../../lang/perl5/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.else # !perl
CONFIGURE_ARGS+=	--disable-perl-cc-checks
CONFIGURE_ARGS+=	--with-perl-modules=no
CONFIGURE_ENV+=		ac_cv_path_PERLPROG=""
CONFIGURE_ARGS+=	--disable-embedded-perl
.endif
