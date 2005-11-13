# $NetBSD: options.mk,v 1.4 2005/11/13 22:48:32 heinz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.spamassassin
PKG_SUPPORTED_OPTIONS=	\
			spamassassin-perl-warnings \
			spamassassin-taint-checks \
			spamassassin-test-awl-sql \
			spamassassin-test-bayes-sql \
			spamassassin-test-net \
			spamassassin-test-prefork \
			ssl
PKG_OPTIONS_LEGACY_OPTS+= \
			awl-sql-tests:spamassassin-test-awl-sql \
			bayes-sql-tests:spamassassin-test-bayes-sql \
			net-tests:spamassassin-test-net \
			perl-taint-checks:spamassassin-taint-checks \
			perl-warnings:spamassassin-perl-warnings

#
# Default options
#
PKG_SUGGESTED_OPTIONS=	spamassassin-taint-checks \
			spamassassin-perl-warnings \
			ssl
.include "../../mk/bsd.options.mk"

#
# change t/config according to all the options
#
SUBST_CLASSES+=		satests
SUBST_STAGE.satests=	post-configure
SUBST_FILES.satests=	t/config
SUBST_SED.satests=	\
	-e s!awl_sql_tests=n!awl_sql_tests=${_AWL_SQL_TEST}! \
	-e s!bayes_sql_tests=n!bayes_sql_tests=${_BAYES_SQL_TEST}! \
	-e s!run_net_tests=n!run_net_tests=${_NET_TEST}! \
	-e s!prefork_stress_test=n!prefork_stress_test=${_PREFORK_TEST}!

#
# Enable tests of the SQL storage module for the automatic whitelist
# (AWL). This option enables interactive questions about the database
# configuration during 'configure' phase.
#
.if !empty(PKG_OPTIONS:Mspamassassin-test-awl-sql)
_AWL_SQL_TEST=y
.else
_AWL_SQL_TEST=n
.endif

#
# Enable tests of the SQL storage module for Bayes information.
# This option enables interactive questions about the database
# configuration during 'configure' phase.
#
.if !empty(PKG_OPTIONS:Mspamassassin-test-bayes-sql)
_BAYES_SQL_TEST=y
.else
_BAYES_SQL_TEST=n
.endif

#
# Enable Internet based tests during 'make test' (Razor, Pyzor, etc.)
#
.if !empty(PKG_OPTIONS:Mspamassassin-test-net)
_NET_TEST=y
.else
_NET_TEST=n
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
_PREFORK_TEST=y
.else
_PREFORK_TEST=n
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
