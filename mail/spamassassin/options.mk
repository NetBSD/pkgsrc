# $NetBSD: options.mk,v 1.8 2009/03/07 13:25:19 seb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.spamassassin
PKG_SUPPORTED_OPTIONS=	inet6
PKG_SUPPORTED_OPTIONS+=	online-tests
PKG_SUPPORTED_OPTIONS+=	spamassassin-perl-warnings
PKG_SUPPORTED_OPTIONS+=	spamassassin-taint-checks
PKG_SUPPORTED_OPTIONS+=	spamassassin-test-awl-sql
PKG_SUPPORTED_OPTIONS+=	spamassassin-test-bayes-sql
PKG_SUPPORTED_OPTIONS+=	spamassassin-test-prefork
PKG_SUPPORTED_OPTIONS+=	ssl

PKG_OPTIONS_LEGACY_OPTS+=	awl-sql-tests:spamassassin-test-awl-sql
PKG_OPTIONS_LEGACY_OPTS+=	bayes-sql-tests:spamassassin-test-bayes-sql
PKG_OPTIONS_LEGACY_OPTS+=	net-tests:online-tests
PKG_OPTIONS_LEGACY_OPTS+=	perl-taint-checks:spamassassin-taint-checks
PKG_OPTIONS_LEGACY_OPTS+=	perl-warnings:spamassassin-perl-warnings
PKG_OPTIONS_LEGACY_OPTS+=	spamassassin-test-net:online-tests

#
# Default options
#
PKG_SUGGESTED_OPTIONS=	inet6 spamassassin-taint-checks
PKG_SUGGESTED_OPTIONS+=	spamassassin-perl-warnings ssl

.include "../../mk/bsd.options.mk"

#
# change t/config according to all the options
#
SUBST_CLASSES+=		satests
SUBST_STAGE.satests=	post-configure
SUBST_FILES.satests=	t/config
SUBST_SED.satests=	-e s!awl_sql_tests=n!awl_sql_tests=${AWL_SQL_TEST}!
SUBST_SED.satests+=	-e s!bayes_sql_tests=n!bayes_sql_tests=${BAYES_SQL_TEST}!
SUBST_SED.satests+=	-e s!run_net_tests=n!run_net_tests=${NET_TEST}!
SUBST_SED.satests+=	-e s!prefork_stress_test=n!prefork_stress_test=${PREFORK_TEST}!

#
# Enable tests of the SQL storage module for the automatic whitelist
# (AWL). This option enables interactive questions about the database
# configuration during 'configure' phase.
#
.if !empty(PKG_OPTIONS:Mspamassassin-test-awl-sql)
AWL_SQL_TEST=y
.else
AWL_SQL_TEST=n
.endif

#
# Enable tests of the SQL storage module for Bayes information.
# This option enables interactive questions about the database
# configuration during 'configure' phase.
#
.if !empty(PKG_OPTIONS:Mspamassassin-test-bayes-sql)
BAYES_SQL_TEST=y
.else
BAYES_SQL_TEST=n
.endif

#
# Enable Internet based tests during 'make test' (Razor, Pyzor, etc.)
#
.if !empty(PKG_OPTIONS:Monline-tests)
NET_TEST=y
.else
NET_TEST=n
.endif

#
# Enable Perl warnings in spamd and spamassassin
#
.if !empty(PKG_OPTIONS:Mspamassassin-perl-warnings)
MAKE_PARAMS+=		PERL_WARN=yes
.else
MAKE_PARAMS+=		PERL_WARN=no
.endif

#
# Enable Perl taint checks in spamd and spamassassin to improve security
#
.if !empty(PKG_OPTIONS:Mspamassassin-taint-checks)
MAKE_PARAMS+=		PERL_TAINT=yes
.else
MAKE_PARAMS+=		PERL_TAINT=no
.endif

#
# Enable spamd prefork stress test (will kill any processes containing the
# string 'spam child' in their process title).
#
.if !empty(PKG_OPTIONS:Mspamassassin-test-prefork)
PREFORK_TEST=y
.else
PREFORK_TEST=n
.endif

#
# Build spamc and spamd with support for connections over SSL
#
.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
DEPENDS+=		p5-IO-Socket-SSL>=0.92:../../security/p5-IO-Socket-SSL
CONFIGURE_ARGS+=	--enable-ssl
MAKE_PARAMS+=		ENABLE_SSL=yes
.else
CONFIGURE_ARGS+=	--disable-ssl
MAKE_PARAMS+=		ENABLE_SSL=no
.endif

#
# Be prepared for IPv6 nameservers
#
.if !empty(PKG_OPTIONS:Minet6)
DEPENDS+=		p5-IO-Socket-INET6-[0-9]*:../../net/p5-IO-Socket-INET6
.endif
