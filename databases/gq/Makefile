# $NetBSD: Makefile,v 1.13 2003/11/12 03:39:39 jschauma Exp $
#

DISTNAME=	gq-0.6.0
PKGREVISION=	1
CATEGORIES=	databases net
MASTER_SITES=	http://biot.com/gq/download/ \
		${MASTER_SITE_SOURCEFORGE:=gqclient/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://biot.com/gq/
COMMENT=	GTK-based LDAP client

BUILD_USES_MSGFMT=	yes
DEPENDS+=		gnome1-dirs>=1.0:../../misc/gnome1-dirs

USE_BUILDLINK2=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

LIBS+=			-ldes
CONFIGURE_ARGS+=	--enable-browser-dnd
CONFIGURE_ARGS+=	--with-ssl-prefix=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--enable-cache

.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../databases/openldap/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
