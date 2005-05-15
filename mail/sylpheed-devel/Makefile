# $NetBSD: Makefile,v 1.6 2005/05/15 13:32:27 chris Exp $

DISTNAME=	sylpheed-1.9.10
CATEGORIES=	mail news x11
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sylpheed-claws/}
MASTER_SITES=	http://sylpheed.good-day.net/sylpheed/v1.9/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	chris@NetBSD.org
HOMEPAGE=	http://sylpheed.good-day.net/index.cgi.en
COMMENT=	X based e-mail and netnews client

BUILD_USES_MSGFMT=	yes
DEPENDS+=		metamail>=2.7:../../mail/metamail

CONFLICTS=		sylpheed-claws-[0-9]* sylpheed-gtk2-[0-9]*

USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=            yes
USE_X11=		yes
USE_GNU_TOOLS+=		make

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-nls
CONFIGURE_ARGS+=	--enable-ssl
CONFIGURE_ARGS+=	--enable-gpgme
CONFIGURE_ARGS+=	--enable-compface

PKG_SYSCONFSUBDIR=	sylpheed
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

PKG_OPTIONS_VAR=        PKG_OPTIONS.sylpheed-devel
PKG_SUPPORTED_OPTIONS=  jpilot ldap inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
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

.if !empty(PKG_OPTIONS:Mldap)
CONFIGURE_ARGS+=	--enable-ldap
.include "../../databases/openldap/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mjpilot)
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
.include "../../security/gpgme/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
