# $NetBSD: Makefile,v 1.16 2003/05/02 11:55:42 wiz Exp $
#

DISTNAME=	sylpheed-0.8.11claws
PKGNAME=	sylpheed-claws-0.8.11
PKGREVISION=	2
CATEGORIES=	mail news x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sylpheed-claws/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	chris@netbsd.org
HOMEPAGE=	http://sylpheed-claws.sourceforge.net/
COMMENT=	X based e-mail and netnews client

BUILD_USES_MSGFMT=	yes

CONFLICTS=	sylpheed-[0-9]*

USE_BUILDLINK2=		yes
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
USE_GMAKE=		yes

GNU_CONFIGURE=		yes
# Force gnome detection off to avoid installing some extra files
CONFIGURE_ENV+=		ac_cv_path_GNOME_CONFIG="no"
CONFIGURE_ARGS+=	--enable-nls
CONFIGURE_ARGS+=	--enable-openssl
CONFIGURE_ARGS+=	--enable-gpgme
CONFIGURE_ARGS+=	--enable-compface
CONFIGURE_ARGS+=	--enable-aspell

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
.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../security/gpgme/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../textproc/aspell/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
