# $NetBSD: Makefile,v 1.51 2006/10/21 19:54:59 joerg Exp $

.include "Makefile.common"

#PKGNAME=	sylpheed-claws-${SYLPHEED_VERSION}

MAINTAINER=	reed@NetBSD.org
COMMENT=	X based e-mail and netnews client

CONFLICTS=		sylpheed-[0-9]* sylpheed-gtk2-[0-9]*

USE_TOOLS+=		msgfmt pkg-config
PKGCONFIG_OVERRIDE+=	sylpheed-claws.pc.in

#BUILDLINK_ABI_DEPENDS.libetpan+=	libetpan>=0.46

CONFIGURE_ARGS+=        --enable-aspell
CONFIGURE_ARGS+=	--enable-nls
CONFIGURE_ARGS+=	--enable-openssl
CONFIGURE_ARGS+=	--enable-gpgme
CONFIGURE_ARGS+=	--enable-compface
#CONFIGURE_ARGS+=	--enable-libetpan
CONFIGURE_ARGS+=	--disable-libetpan
CONFIGURE_ARGS+=	--disable-trayicon-plugin
CONFIGURE_ARGS+=	--disable-image-viewer-plugin
CONFIGURE_ARGS+=	--disable-clamav-plugin
CONFIGURE_ARGS+=	--disable-dillo-viewer-plugin
CONFIGURE_ARGS+=	--disable-spamassassin-plugin
CONFIGURE_ARGS+=	--disable-mathml-viewer-plugin
CONFIGURE_ARGS+=	--disable-pgpcore-plugin
CONFIGURE_ARGS+=	--disable-pgpmime-plugin
CONFIGURE_ARGS+=	--disable-pgpinline-plugin
CONFIGURE_ARGS+=	--disable-bogofilter-plugin
CONFIGURE_ARGS+=	--disable-gnomeprint

# for SMTP, POP3 and IMAP over SSL
# set these just in case we don't have a pkg-config file for openssl
CONFIGURE_ENV+=		OPENSSL_CFLAGS="-I${BUILDLINK_PREFIX.openssl}/include"
CONFIGURE_ENV+=		OPENSSL_LIBS="-L${BUILDLINK_PREFIX.openssl}/lib -lssl -lcrypto"

PKG_SYSCONFSUBDIR=	sylpheed-claws
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

.include "../../mk/bsd.prefs.mk"

FACES_IS_INSTALLED!=	${PKG_INFO} -e faces || ${ECHO}
.if empty(FACES_IS_INSTALLED)
.  include "../../graphics/compface/buildlink3.mk"
.else
.  include "../../mail/faces/buildlink3.mk"
.endif

EGDIR=		${PREFIX}/share/examples/sylpheed-claws
CONF_FILES=	${EGDIR}/mime.types ${PKG_SYSCONFDIR}/mime.types

PKG_OPTIONS_VAR=	PKG_OPTIONS.sylpheed-claws
PKG_SUPPORTED_OPTIONS=	jpilot ldap inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mjpilot)
CONFIGURE_ARGS+=	--enable-jpilot
.  include "../../comms/pilot-link-libs/buildlink3.mk"
.  include "../../comms/jpilot/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-jpilot
.endif

.if !empty(PKG_OPTIONS:Mldap)
CONFIGURE_ARGS+=	--enable-ldap
.  include "../../databases/openldap-client/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-ldap
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/mime.types ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/sylpheed*.png ${PREFIX}/share/sylpheed-claws

.include "../../converters/libiconv/buildlink3.mk"
#.include "../../mail/libetpan/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
