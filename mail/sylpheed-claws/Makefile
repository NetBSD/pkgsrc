# $NetBSD: Makefile,v 1.36 2004/10/03 00:12:54 tv Exp $
#

.include "Makefile.common"

#PKGNAME=	sylpheed-claws-${SYLPHEED_VERSION}
PKGREVISION=	1

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
BUILD_DEFS+=		USE_INET6 USE_OPENLDAP

.if defined(USE_INET6) && !empty(USE_INET6:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

FACES_IS_INSTALLED!=	${PKG_INFO} -e faces || ${ECHO}
.if empty(FACES_IS_INSTALLED)
.  include "../../graphics/compface/buildlink3.mk"
.else
.  include "../../mail/faces/buildlink3.mk"
.endif

.if defined(USE_OPENLDAP) && ${USE_OPENLDAP} == YES
CONFIGURE_ARGS+=	--enable-ldap
.include "../../databases/openldap/buildlink3.mk"
.endif

EGDIR=		${PREFIX}/share/examples/sylpheed
CONF_FILES=	${EGDIR}/mime.types ${PKG_SYSCONFDIR}/mime.types

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/mime.types ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/sylpheed*.png ${PREFIX}/share/sylpheed-claws

.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/gpgme03/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
