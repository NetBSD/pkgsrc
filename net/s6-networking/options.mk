# $NetBSD: options.mk,v 1.9 2025/06/04 13:29:33 schmonz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.s6-networking
PKG_OPTIONS_OPTIONAL_GROUPS=	tls
PKG_OPTIONS_GROUP.tls=		bearssl openssl
PKG_SUPPORTED_OPTIONS+=		execline
PKG_SUGGESTED_OPTIONS+=		execline bearssl
PKG_OPTIONS_LEGACY_OPTS+=	tls:bearssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mexecline)
DEPENDS+=		execline-[0-9]*:../../lang/execline
.  include "../../lang/execline/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-execline
.else
CONFIGURE_ARGS+=	--disable-execline
.endif

PLIST_VARS=		tls bearssl libtls

.if !empty(PKG_OPTIONS:Mbearssl)
PLIST.tls=		yes
PLIST.bearssl=		yes
.  include "../../security/bearssl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-ssl=bearssl
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
PLIST.tls=		yes
PLIST.libtls=		yes
BUILDLINK_API_DEPENDS.libretls+=	libretls>=3.8.1
.  include "../../security/libretls/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-ssl=libtls
.endif

.if !empty(PLIST.tls) && ${PLIST.tls} == "yes"
PKG_USERS_VARS+=	UCSPI_SSL_USER
PKG_GROUPS_VARS+=	UCSPI_SSL_GROUP
PKG_GROUPS+=		${UCSPI_SSL_GROUP}
PKG_USERS+=		${UCSPI_SSL_USER}:${UCSPI_SSL_GROUP}

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	s6-pkgsrc-cadir
SUBST_VARS.paths=	SH SETENV SSLCERTS

.PHONY: do-extract-cadir do-install-cadir
post-extract: do-extract-cadir
do-extract-cadir:
	for f in s6-pkgsrc-cadir; do \
		${CP} ${FILESDIR}/$$f.sh ${WRKSRC}/$$f; \
	done
post-install: do-install-cadir
do-install-cadir:
	for f in s6-pkgsrc-cadir; do \
		${INSTALL_SCRIPT} ${WRKSRC}/$$f ${DESTDIR}${PREFIX}/bin/$$f; \
	done
.endif
