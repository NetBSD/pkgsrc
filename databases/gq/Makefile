# $NetBSD: Makefile,v 1.28 2006/01/24 07:31:59 wiz Exp $
#

DISTNAME=	gq-1.0beta1
PKGREVISION=	7
CATEGORIES=	databases net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gqclient/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://biot.com/gq/
COMMENT=	GTK-based LDAP client

USE_DIRS+=		gnome2-1.5
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config

CONFIGURE_ARGS+=	--enable-browser-dnd
CONFIGURE_ARGS+=	--with-ssl-prefix=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--enable-cache

.include "../../security/openssl/buildlink3.mk"
.include "../../databases/openldap/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
