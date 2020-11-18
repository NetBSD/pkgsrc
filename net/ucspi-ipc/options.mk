# $NetBSD: options.mk,v 1.1 2020/11/18 15:18:39 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ucspi-ipc
PKG_SUPPORTED_OPTIONS+=	perl

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		perl
.PHONY: do-install-ipcperl
.if !empty(PKG_OPTIONS:Mperl)
.include "../../lang/perl5/buildlink3.mk"
USE_TOOLS+=		perl:run
DJB_CONFIG_CMDS+=	${ECHO} ${PERL5} > conf-perl; \
			${ECHO} it-ipcperl >> it=d;
PLIST.perl=		yes
do-install-ipcperl:
	${INSTALL_PROGRAM} ${WRKSRC}/command/ipcperl ${DESTDIR}${PREFIX}/bin
.else
do-install-ipcperl:
	${DO_NADA}
.endif
