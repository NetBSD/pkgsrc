# $NetBSD: Makefile,v 1.122 2022/06/28 11:34:16 wiz Exp $

INSTALLATION_DIRS+=	${EGDIR}
INSTALLATION_DIRS+=	share/claws-mail

PKGREVISION= 3
.include "Makefile.common"

PKGNAME=	claws-mail-${CLAWS_VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Email client and news reader based on GTK+

CONFLICTS+=	sylpheed-claws-[0-9]*

USE_TOOLS+=		msgfmt
TOOLS_BROKEN+=		perl
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

.include "options.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.if "${OPSYS}" != "Darwin"
.include "../../x11/startup-notification/buildlink3.mk"
.endif
.include "../../x11/libSM/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
