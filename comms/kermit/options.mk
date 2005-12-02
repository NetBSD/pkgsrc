# $NetBSD: options.mk,v 1.1 2005/12/02 17:01:35 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kermit
PKG_SUPPORTED_OPTIONS=	kermit-suid-uucp
PKG_OPTIONS_OPTIONAL_GROUPS+=	socks
PKG_OPTIONS_GROUP.socks=	socks4 socks5

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mkermit-suid-uucp)
BINOWN=		uucp
BINMODE=	4555
.endif

.if !empty(PKG_OPTIONS:Msocks4)
KFLAGS+=	-DSOCKS
LIBS+=		-L${BUILDLINK_PREFIX.socks4}/lib -lsocks4
.include "../../net/socks4/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Msocks5)
KFLAGS+=	-DSOCKS -DCK_SOCKS5
LIBS+=		-L${BUILDLINK_PREFIX.socks4}slib -lsocks5
.include "../../net/socks5/buildlink3.mk"
.endif
