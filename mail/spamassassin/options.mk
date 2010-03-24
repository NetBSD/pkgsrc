# $NetBSD: options.mk,v 1.9 2010/03/24 21:41:10 heinz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.spamassassin
PKG_SUPPORTED_OPTIONS=	inet6
PKG_SUPPORTED_OPTIONS+=	ssl

#
# Default options
#
PKG_SUGGESTED_OPTIONS=	inet6 ssl

.include "../../mk/bsd.options.mk"

#
# change t/config according to enable/disable software options
#
AWL_SQL_TEST?=		n  # to  enable tests, set to 'y' on make command line
BAYES_SQL_TEST?=	n  # to  enable tests, set to 'y' on make command line
LONG_TEST?=		y  # to disable tests, set to 'n' on make command line
NET_TEST?=		y  # to disable tests, set to 'n' on make command line
PREFORK_TEST?=		n  # to  enable tests, set to 'y' on make command line
ROOT_TEST?=		n  # to  enable tests, set to 'y' on make command line

SUBST_CLASSES+=		satests
SUBST_STAGE.satests=	post-configure
SUBST_FILES.satests=	t/config
SUBST_SED.satests=	-e s!awl_sql_tests=n!awl_sql_tests=${AWL_SQL_TEST}!
SUBST_SED.satests+=	-e s!bayes_sql_tests=n!bayes_sql_tests=${BAYES_SQL_TEST}!
SUBST_SED.satests+=	-e s!run_long_tests=n!run_long_tests=${LONG_TEST}!
SUBST_SED.satests+=	-e s!run_net_tests=n!run_net_tests=${NET_TEST}!
SUBST_SED.satests+=	-e s!run_root_tests=n!run_root_tests=${ROOT_TEST}!
SUBST_SED.satests+=	-e s!prefork_stress_test=n!prefork_stress_test=${PREFORK_TEST}!

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
