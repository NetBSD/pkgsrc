# $NetBSD: Makefile,v 1.9 2002/12/08 00:15:22 chris Exp $

DISTNAME=	sylpheed-0.8.6claws
PKGNAME=	sylpheed-claws-0.8.6
CATEGORIES=	mail news x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sylpheed-claws/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ptiJo@noos.fr
HOMEPAGE=	http://sylpheed-claws.sourceforge.net/
COMMENT=	X based e-mail and netnews client

BUILD_USES_MSGFMT=	yes

CONFLICTS=	sylpheed-[0-9]*

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_X11BASE=		yes
USE_GMAKE=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-nls
CONFIGURE_ARGS+=	--enable-ssl
CONFIGURE_ARGS+=	--enable-gpgme
CONFIGURE_ARGS+=	--enable-compface

PKG_SYSCONFSUBDIR=	sylpheed
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

BUILDLINK_DEPENDS.gpgme=	gpgme>=0.3.5

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

CONF_FILES=	${FILESDIR}/mime.types ${PKG_SYSCONFDIR}/mime.types

.include "../../converters/libiconv/buildlink2.mk"
.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../security/gpgme/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
