# $NetBSD: options.mk,v 1.12 2023/06/07 15:11:53 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ucspi-ssl
PKG_SUPPORTED_OPTIONS+=	perl

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		perl
.PHONY: do-install-sslperl
.if !empty(PKG_OPTIONS:Mperl)
.include "../../lang/perl5/buildlink3.mk"
USE_TOOLS+=		perl:run
DJB_CONFIG_CMDS+=	${ECHO} ${PERL5} > conf-perl; \
			${ECHO} it-sslperl >> src/it=d;
PLIST.perl=		yes
do-install-sslperl:
	${INSTALL_PROGRAM} ${WRKSRC}/command/sslperl ${DESTDIR}${PREFIX}/bin
.else
do-install-sslperl:
	${DO_NADA}
.endif
