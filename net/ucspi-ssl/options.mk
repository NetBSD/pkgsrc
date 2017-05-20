# $NetBSD: options.mk,v 1.4 2017/05/20 01:39:12 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ucspi-ssl
PKG_SUPPORTED_OPTIONS+=	perl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mperl)
.include "../../lang/perl5/buildlink3.mk"
USE_TOOLS+=		perl:run
SSL_PROGRAMS+=		sslperl
PLIST_SRC+=		${PKGDIR}/PLIST.perl
DJB_CONFIG_CMDS+=	${ECHO} ${PERL5} > conf-perl;
.else
DJB_BUILD_ARGS+=	- sslperl
.endif
