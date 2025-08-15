# $NetBSD: options.mk,v 1.2 2025/08/15 09:06:10 dkazankov Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.polyorb
PKG_SUPPORTED_OPTIONS=		polyorb-cs-event polyorb-cs-ir polyorb-cs-naming \
				polyorb-cs-notification polyorb-cs-time \
				polyorb-gnatcoll openssl
PKG_OPTIONS_NONEMPTY_SETS=	polyorb-ap polyorb-pp
PKG_OPTIONS_SET.polyorb-ap=	polyorb-ap-corba polyorb-ap-dsa polyorb-ap-moma polyorb-ap-aws
PKG_OPTIONS_SET.polyorb-pp=	polyorb-pp-giop polyorb-pp-soap polyorb-pp-srp polyorb-pp-dns
PKG_SUGGESTED_OPTIONS=		polyorb-ap-corba polyorb-ap-dsa polyorb-ap-moma \
				polyorb-pp-giop polyorb-pp-soap polyorb-pp-srp polyorb-pp-dns \
				polyorb-cs-event polyorb-cs-ir polyorb-cs-naming \
				polyorb-cs-notification polyorb-cs-time \
				polyorb-gnatcoll openssl

.include "../../mk/bsd.fast.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopenssl)
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
.endif

.if !empty(PKG_OPTIONS:Mpolyorb-gnatcoll)
.include "../../textproc/ada-xmlada-25/buildlink3.mk"
.include "../../devel/ada-libgpr-25/buildlink3.mk"
.include "../../devel/ada-gnatcoll-core-25/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gnatcoll
.endif

.if !empty(PKG_OPTIONS:Mpolyorb-ap-aws)
# AWS personality is not currently compiling
#APP_PERSONALITIES+=	aws
#.include "../../textproc/ada-xmlada-25/buildlink3.mk"
.endif
.if !empty(PKG_OPTIONS:Mpolyorb-ap-corba)
APP_PERSONALITIES+=	corba
.endif
.if !empty(PKG_OPTIONS:Mpolyorb-ap-dsa)
APP_PERSONALITIES+=	dsa
.endif
.if !empty(PKG_OPTIONS:Mpolyorb-ap-moma)
APP_PERSONALITIES+=	moma
.endif

.if !empty(PKG_OPTIONS:Mpolyorb-pp-dns)
PROTOCOL_PERSONALITIES+=	dns
.endif
.if !empty(PKG_OPTIONS:Mpolyorb-pp-giop)
PROTOCOL_PERSONALITIES+=	giop
.endif
.if !empty(PKG_OPTIONS:Mpolyorb-pp-soap)
PROTOCOL_PERSONALITIES+=	soap
.include "../../textproc/ada-xmlada-25/buildlink3.mk"
.endif
.if !empty(PKG_OPTIONS:Mpolyorb-pp-srp)
PROTOCOL_PERSONALITIES+=	srp
.endif

.if !empty(PKG_OPTIONS:Mpolyorb-cs-event)
CORBA_SERVICES+=	event
.endif
.if !empty(PKG_OPTIONS:Mpolyorb-cs-ir)
CORBA_SERVICES+=	ir
.endif
.if !empty(PKG_OPTIONS:Mpolyorb-cs-naming)
CORBA_SERVICES+=	naming
.endif
.if !empty(PKG_OPTIONS:Mpolyorb-cs-notification)
CORBA_SERVICES+=	notification
.endif
.if !empty(PKG_OPTIONS:Mpolyorb-cs-time)
CORBA_SERVICES+=	time
.endif
