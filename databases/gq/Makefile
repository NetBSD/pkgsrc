# $NetBSD: Makefile,v 1.15 2004/01/23 21:50:43 jmmv Exp $
#

DISTNAME=	gq-1.0beta1
PKGREVISION=	1
CATEGORIES=	databases net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gqclient/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://biot.com/gq/
COMMENT=	GTK-based LDAP client

DEPENDS+=		gnome2-dirs>=1.0:../../misc/gnome2-dirs

USE_BUILDLINK2=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--enable-browser-dnd
CONFIGURE_ARGS+=	--with-ssl-prefix=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--enable-cache

.include "../../security/openssl/buildlink2.mk"
.include "../../databases/openldap/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
