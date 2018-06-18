# $NetBSD: options.mk,v 1.5 2018/06/18 11:00:21 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ucspi-ssl
PKG_SUPPORTED_OPTIONS+=	perl

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		perl
.if !empty(PKG_OPTIONS:Mperl)
.include "../../lang/perl5/buildlink3.mk"
USE_TOOLS+=		perl:run
DJB_CONFIG_CMDS+=	${ECHO} ${PERL5} > conf-perl;
PLIST.perl=		yes
do-install-sslperl:
	${INSTALL_PROGRAM} ${WRKSRC}/command/sslperl ${DESTDIR}${PREFIX}/bin
.else
DJB_BUILD_ARGS+=	- sslperl
do-install-sslperl:
	${DO_NADA}
.endif
