# $NetBSD: options.mk,v 1.1 2025/08/15 08:10:03 dkazankov Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.polyorb
PKG_SUPPORTED_OPTIONS=		cs-event cs-ir cs-naming cs-notification cs-time \
				gnatcoll openssl
PKG_OPTIONS_NONEMPTY_SETS=	ap pp
PKG_OPTIONS_SET.ap=		ap-corba ap-dsa ap-moma ap-aws
PKG_OPTIONS_SET.pp=		pp-giop pp-soap pp-srp pp-dns
PKG_SUGGESTED_OPTIONS=		ap-corba ap-dsa ap-moma \
				pp-giop pp-soap pp-srp pp-dns \
				cs-event cs-ir cs-naming cs-notification cs-time \
				gnatcoll openssl

.include "../../mk/bsd.fast.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopenssl)
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
.endif

.if !empty(PKG_OPTIONS:Mgnatcoll)
.include "../../textproc/ada-xmlada-25/buildlink3.mk"
.include "../../devel/ada-libgpr-25/buildlink3.mk"
.include "../../devel/ada-gnatcoll-core-25/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gnatcoll
.endif

.if !empty(PKG_OPTIONS:Map-aws)
# AWS personality is not currently compiling
#APP_PERSONALITIES+=	aws
#.include "../../textproc/ada-xmlada-25/buildlink3.mk"
.endif
.if !empty(PKG_OPTIONS:Map-corba)
APP_PERSONALITIES+=	corba
.endif
.if !empty(PKG_OPTIONS:Map-dsa)
APP_PERSONALITIES+=	dsa
.endif
.if !empty(PKG_OPTIONS:Map-moma)
APP_PERSONALITIES+=	moma
.endif

.if !empty(PKG_OPTIONS:Mpp-dns)
PROTOCOL_PERSONALITIES+=	dns
.endif
.if !empty(PKG_OPTIONS:Mpp-giop)
PROTOCOL_PERSONALITIES+=	giop
.endif
.if !empty(PKG_OPTIONS:Mpp-soap)
PROTOCOL_PERSONALITIES+=	soap
.include "../../textproc/ada-xmlada-25/buildlink3.mk"
.endif
.if !empty(PKG_OPTIONS:Mpp-srp)
PROTOCOL_PERSONALITIES+=	srp
.endif

.if !empty(PKG_OPTIONS:Mcs-event)
CORBA_SERVICES+=	event
.endif
.if !empty(PKG_OPTIONS:Mcs-ir)
CORBA_SERVICES+=	ir
.endif
.if !empty(PKG_OPTIONS:Mcs-naming)
CORBA_SERVICES+=	naming
.endif
.if !empty(PKG_OPTIONS:Mcs-notification)
CORBA_SERVICES+=	notification
.endif
.if !empty(PKG_OPTIONS:Mcs-time)
CORBA_SERVICES+=	time
.endif
