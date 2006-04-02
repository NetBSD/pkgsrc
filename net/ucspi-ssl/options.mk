# $NetBSD: options.mk,v 1.2 2006/04/02 17:44:16 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ucspi-ssl
PKG_SUPPORTED_OPTIONS+=	ucspi-ssl-perl tls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mucspi-ssl-perl)
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
