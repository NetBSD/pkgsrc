# $NetBSD: Makefile,v 1.91 2018/08/16 18:54:57 adam Exp $

INSTALLATION_DIRS+=	${EGDIR}
INSTALLATION_DIRS+=	share/claws-mail

PKGREVISION= 8
.include "Makefile.common"

PKGNAME=	claws-mail-${CLAWS_VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	X based e-mail and netnews client

CONFLICTS+=	sylpheed-claws-[0-9]*

USE_TOOLS+=		msgfmt
PKGCONFIG_OVERRIDE+=	claws-mail.pc.in

PKG_SYSCONFSUBDIR=	claws-mail
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

CONFIGURE_ENV+=	ac_cv_path_GPGME_CONFIG=no

.include "../../mk/bsd.prefs.mk"

FACES_IS_INSTALLED!=	${PKG_INFO} -e faces || ${ECHO}
.if empty(FACES_IS_INSTALLED)
.  include "../../graphics/compface/buildlink3.mk"
.else
.  include "../../mail/faces/buildlink3.mk"
.endif

EGDIR=		${PREFIX}/share/examples/claws-mail
CONF_FILES=	${EGDIR}/mime.types ${PKG_SYSCONFDIR}/mime.types

PKG_OPTIONS_VAR=	PKG_OPTIONS.claws-mail
PKG_SUPPORTED_OPTIONS=	claws-mail-jpilot ldap inet6
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mclaws-mail-jpilot)
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

INSTALLATION_DIRS+=	share/applications

post-install:
	${INSTALL_DATA} ${FILESDIR}/mime.types ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/claws-mail*.png \
		${DESTDIR}${PREFIX}/share/claws-mail
	${INSTALL_DATA} ${WRKSRC}/claws-mail.desktop \
		${DESTDIR}${PREFIX}/share/applications
.if exists(files/shred.${OPSYS})
	${INSTALL_SCRIPT} files/shred.${OPSYS} \
		${DESTDIR}${PREFIX}/bin/claws-mail-shred
PLIST_SRC=	PLIST
PLIST_SRC+=	PLIST.shred
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
