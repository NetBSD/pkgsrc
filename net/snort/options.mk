# $NetBSD: options.mk,v 1.11 2024/05/10 19:46:53 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.snort

PKG_SUPPORTED_OPTIONS=	debug ssl snmp snort-gre
PKG_SUPPORTED_OPTIONS+=	snort-dynamicplugin snort-timestats
PKG_SUPPORTED_OPTIONS+=	snort-rulestate


PKG_OPTIONS_OPTIONAL_GROUPS=	flex
PKG_OPTIONS_GROUP.flex=		snort-flexresp snort-flexresp2

.include "../../mk/bsd.options.mk"

###
### Please note that a large number of these options remain un-tested
### for this package.
###

###
### Enable dynamically loadable preprocessors, detection engine
### and rules libraries.
###
.if !empty(PKG_OPTIONS:Msnort-dynamicplugin)
CONFIGURE_ARGS+=	--enable-dynamicplugin
.endif

###
### Enable rule state configuration feature
###
.if !empty(PKG_OPTIONS:Msnort-rulestate)
CONFIGURE_ARGS+=	--enable-rulestate
.endif

###
### Enable real-time performance statistics
###
.if !empty(PKG_OPTIONS:Msnort-timestats)
CONFIGURE_ARGS+=	--enable-timestats
.endif

###
### Enable debug support
###
.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif

###
### Support for openssl (used by the XML output plugin)
###
.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--with-openssl
.endif

###
### Enable GRE decoder
###
.if !empty(PKG_OPTIONS:Msnort-gre)
CONFIGURE_ARGS+=	--enable-gre
.endif

###
### Enable SNMP alerting code
###
.if !empty(PKG_OPTIONS:Msnmp)
CONFIGURE_ARGS+=	--with-snmp
.endif

###
### Flexible Responses on hostile connection attempts (untested)
###
.if !empty(PKG_OPTIONS:Msnort-flexresp)
.include "../../devel/libnet10/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-flexresp
CONFIGURE_ARGS+=	--with-libnet-includes=${BUILDLINK_PREFIX.libnet10}/include/libnet10
CONFIGURE_ARGS+=	--with-libnet-libraries=${BUILDLINK_PREFIX.libnet10}/lib/libnet10
SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_FILES.conf=	configure
SUBST_SED.conf=		-e "s|libnet-config|libnet10-config|g"
SUBST_MESSAGE.conf=	Fixing configuration script.
.endif

###
### NEW Flexible Responses on hostile connection attempts (untested)
###
.if !empty(PKG_OPTIONS:Msnort-flexresp2)
.include "../../devel/libnet11/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libnet-includes=${BUILDLINK_PREFIX.libnet11}/include/libnet11
CONFIGURE_ARGS+=	--with-libnet-libraries=${BUILDLINK_PREFIX.libnet11}/lib/libnet11
CONFIGURE_ARGS+=	--enable-flexresp2
SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_FILES.conf=	configure
SUBST_SED.conf=		-e "s|libnet-config|libnet11-config|g"
SUBST_MESSAGE.conf=	Fixing configuration script.
.endif
