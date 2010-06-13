# $NetBSD: Makefile,v 1.40 2010/06/13 22:44:00 wiz Exp $

DISTNAME=	gq-1.2.3
PKGREVISION=	5
CATEGORIES=	databases net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gqclient/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://gq-project.org/
COMMENT=	GTK-based LDAP client

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake perl pkg-config intltool
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-browser-dnd
CONFIGURE_ARGS+=	--enable-cache
CONFIGURE_ARGS+=	--with-ssl-prefix=${BUILDLINK_PREFIX.openssl}

.include "../../devel/libglade/buildlink3.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
