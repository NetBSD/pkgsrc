# $NetBSD: Makefile,v 1.65 2004/04/25 04:16:43 xtraeme Exp $

DISTNAME=	sylpheed-0.9.10
PKGREVISION=	3
CATEGORIES=	mail news x11
MASTER_SITES=	http://sylpheed.good-day.net/sylpheed/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	chris@NetBSD.org
HOMEPAGE=	http://sylpheed.good-day.net/index.cgi.en
COMMENT=	X based e-mail and netnews client

BUILD_USES_MSGFMT=	yes
DEPENDS+=		metamail>=2.7:../../mail/metamail

CONFLICTS=		sylpheed-claws-[0-9]* sylpheed-gtk2-[0-9]*

USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
USE_GNU_TOOLS+=		make

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-nls
CONFIGURE_ARGS+=	--enable-ssl
CONFIGURE_ARGS+=	--enable-gpgme
CONFIGURE_ARGS+=	--enable-compface

PKG_SYSCONFSUBDIR=	sylpheed
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../mk/bsd.prefs.mk"
BUILD_DEFS+=		USE_INET6 USE_OPENLDAP USE_JPILOT

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

.if defined(USE_JPILOT) && ${USE_JPILOT} == YES
CONFIGURE_ARGS+=	--enable-jpilot
.include "../../comms/pilot-link-libs/buildlink3.mk"
.include "../../comms/jpilot/buildlink3.mk"
.endif

EGDIR=		${PREFIX}/share/examples/sylpheed
CONF_FILES=	${EGDIR}/mime.types ${PKG_SYSCONFDIR}/mime.types

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/mime.types ${EGDIR}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../security/gpgme03/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
