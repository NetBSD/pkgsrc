# $NetBSD: Makefile,v 1.25 2003/12/14 17:56:39 wiz Exp $
#

DISTNAME=	sylpheed-0.9.7claws
PKGNAME=	sylpheed-claws-0.9.7
PKGREVISION=	1
CATEGORIES=	mail news x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sylpheed-claws/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	chris@NetBSD.org
HOMEPAGE=	http://sylpheed-claws.sourceforge.net/
COMMENT=	X based e-mail and netnews client

BUILD_USES_MSGFMT=	YES

CONFLICTS=		sylpheed-[0-9]* sylpheed-gtk2-[0-9]*

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES
USE_GMAKE=		YES

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/sylpheed-claws.pc.in

GNU_CONFIGURE=		YES
# Force gnome detection off to avoid installing some extra files
CONFIGURE_ENV+=		ac_cv_path_GNOME_CONFIG="no"
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

.if defined(USE_INET6) && ${USE_INET6} == YES
CONFIGURE_ARGS+=	--enable-ipv6
.endif

FACES_IS_INSTALLED!=	${PKG_INFO} -e faces || ${ECHO}
.if empty(FACES_IS_INSTALLED)
.  include "../../graphics/compface/buildlink2.mk"
.else
.  include "../../mail/faces/buildlink2.mk"
.endif

.if defined(USE_OPENLDAP) && ${USE_OPENLDAP} == YES
CONFIGURE_ARGS+=	--enable-ldap
.include "../../databases/openldap/buildlink2.mk"
.endif

EGDIR=		${PREFIX}/share/examples/sylpheed
CONF_FILES=	${EGDIR}/mime.types ${PKG_SYSCONFDIR}/mime.types

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/mime.types ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/sylpheed*.png ${PREFIX}/share/sylpheed

.include "../../converters/libiconv/buildlink2.mk"
.include "../../security/gpgme03/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../textproc/aspell/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
