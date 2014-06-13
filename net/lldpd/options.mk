# $NetBSD: options.mk,v 1.1 2014/06/13 03:06:09 mef Exp $
PKG_OPTIONS_VAR=	PKG_OPTIONS.lldpd
PKG_SUPPORTED_OPTIONS=	json snmp xml
PKG_SUGGESTED_OPTIONS=	json snmp xml
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mjson)
.	include "../../textproc/jansson/buildlink3.mk"
CONFIGURE_ARGS+=	--with-json
.endif

.if !empty(PKG_OPTIONS:Msnmp)
.	include "../../net/net-snmp/buildlink3.mk"
USE_TOOLS+= perl
BUILDLINK_API_DEPENDS.perl+= perl>=5.16.0
.	include "../../lang/perl5/buildlink3.mk"
CONFIGURE_ARGS+=	--with-snmp
.endif

.if !empty(PKG_OPTIONS:Mxml)
.	include "../../textproc/libxml2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-xml
.endif
