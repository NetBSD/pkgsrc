# $NetBSD: options.mk,v 1.10 2020/09/22 09:59:05 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ucspi-ssl
PKG_SUPPORTED_OPTIONS+=	inet6 perl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
DEPENDS+=		ucspi-tcp6>=1.10.7nb1:../../net/ucspi-tcp6
.else
DEPENDS+=		{ucspi-tcp6>=1.10.7nb1,ucspi-tcp-[0-9]*}:../../net/ucspi-tcp
.endif

PLIST_VARS+=		perl
.if !empty(PKG_OPTIONS:Mperl)
.include "../../lang/perl5/buildlink3.mk"
USE_TOOLS+=		perl:run
DJB_CONFIG_CMDS+=	${ECHO} ${PERL5} > conf-perl; \
			${ECHO} it-sslperl >> src/it=d
PLIST.perl=		yes
do-install-sslperl:
	${INSTALL_PROGRAM} ${WRKSRC}/command/sslperl ${DESTDIR}${PREFIX}/bin
.else
do-install-sslperl:
	${DO_NADA}
.endif
