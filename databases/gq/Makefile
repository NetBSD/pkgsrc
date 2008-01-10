# $NetBSD: Makefile,v 1.33 2008/01/10 21:42:50 adam Exp $

DISTNAME=	gq-1.2.3
CATEGORIES=	databases net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gqclient/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://gq-project.org/
COMMENT=	GTK-based LDAP client

USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake perl pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-browser-dnd
CONFIGURE_ARGS+=	--enable-cache
CONFIGURE_ARGS+=	--with-ssl-prefix=${BUILDLINK_PREFIX.openssl}

.include "../../devel/libglade/buildlink3.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
