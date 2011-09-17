# $NetBSD: options.mk,v 1.3 2011/09/17 11:12:26 shattered Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ucspi-ssl
PKG_SUPPORTED_OPTIONS+=	perl tls
PKG_OPTIONS_LEGACY_OPTS+=	ucspi-ssl-perl:perl

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

.if !empty(PKG_OPTIONS:Mtls)
TLS_PATCH=		ucspi-ssl-0.70-ucspitls-0.1.patch
PATCHFILES+=		${TLS_PATCH}
SITES.${TLS_PATCH}=	http://www.suspectclass.com/~sgifford/ucspi-tls/files/
PATCH_DIST_STRIP.${TLS_PATCH}=	-p1
.endif
