# $NetBSD: Makefile,v 1.40 2005/03/06 16:45:47 chris Exp $

.include "Makefile.common"

#PKGNAME=	sylpheed-claws-${SYLPHEED_VERSION}

MAINTAINER=	chris@NetBSD.org
COMMENT=	X based e-mail and netnews client

CONFLICTS=		sylpheed-[0-9]* sylpheed-gtk2-[0-9]*

BUILD_USES_MSGFMT=	YES
USE_PKGINSTALL=		YES
PKGCONFIG_OVERRIDE+=	sylpheed-claws.pc.in

CONFIGURE_ARGS+=        --enable-aspell
CONFIGURE_ARGS+=	--enable-nls
CONFIGURE_ARGS+=	--enable-openssl
CONFIGURE_ARGS+=	--enable-gpgme
CONFIGURE_ARGS+=	--enable-compface
CONFIGURE_ARGS+=	--disable-trayicon-plugin
CONFIGURE_ARGS+=	--disable-image-viewer-plugin
CONFIGURE_ARGS+=	--disable-clamav-plugin
CONFIGURE_ARGS+=	--disable-dillo-viewer-plugin
CONFIGURE_ARGS+=	--disable-spamassassin-plugin
CONFIGURE_ARGS+=	--disable-mathml-viewer-plugin

PKG_SYSCONFSUBDIR=	sylpheed
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../mk/bsd.prefs.mk"

FACES_IS_INSTALLED!=	${PKG_INFO} -e faces || ${ECHO}
.if empty(FACES_IS_INSTALLED)
.  include "../../graphics/compface/buildlink3.mk"
.else
.  include "../../mail/faces/buildlink3.mk"
.endif

EGDIR=		${PREFIX}/share/examples/sylpheed
CONF_FILES=	${EGDIR}/mime.types ${PKG_SYSCONFDIR}/mime.types

PKG_OPTIONS_VAR=	PKG_OPTIONS.sylpheed-claws
PKG_SUPPORTED_OPTIONS=	jpilot ldap inet6

pre-configure:

	cd ${WRKSRC}; ${AUTOCONF}

.include "../../mk/autoconf.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mjpilot)
CONFIGURE_ARGS+=	--enable-jpilot
.  include "../../comms/pilot-link-libs/buildlink3.mk"
.  include "../../comms/jpilot/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mldap)
CONFIGURE_ARGS+=	--enable-ldap
.  include "../../databases/openldap/buildlink3.mk"
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
.include "../../security/gpgme03/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
