# $NetBSD: Makefile,v 1.41 2010/07/14 02:57:26 dholland Exp $

DISTNAME=	gq-1.2.3
PKGREVISION=	6
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
.include "../../security/libgnome-keyring/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
