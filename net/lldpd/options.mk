# $NetBSD: options.mk,v 1.5 2020/06/18 19:40:32 hauke Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.lldpd
PKG_SUPPORTED_OPTIONS=	json snmp xml
PKG_SUGGESTED_OPTIONS=	json snmp xml
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mjson)
.  include "../../textproc/jansson/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msnmp)
.  include "../../net/net-snmp/buildlink3.mk"
.  include "../../lang/perl5/buildlink3.mk"
#  CCLD     lldpd
#  ld: cannot find -lperl
LDFLAGS+=		-L${PREFIX}/${PERL5_SUB_INSTALLARCHLIB}/CORE
CONFIGURE_ARGS+=	--with-snmp
.endif

.if !empty(PKG_OPTIONS:Mxml)
.  include "../../textproc/libxml2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-xml
.endif
