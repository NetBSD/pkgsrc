# $NetBSD: Makefile,v 1.81 2018/08/22 09:43:11 wiz Exp $

DISTNAME=	gq-1.2.3
PKGREVISION=	42
CATEGORIES=	databases net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gqclient/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://gq-project.org/
COMMENT=	GTK-based LDAP client
LICENSE=	gnu-gpl-v2

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
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
