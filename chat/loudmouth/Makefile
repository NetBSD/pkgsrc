# $NetBSD: Makefile,v 1.55 2023/10/24 22:08:22 wiz Exp $

DISTNAME=	loudmouth-1.5.4
PKGREVISION=	3
CATEGORIES=	chat
MASTER_SITES=	https://mcabber.com/files/loudmouth/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mcabber/loudmouth
COMMENT=	Lightweight Jabber client library
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--disable-gtk-doc
CONFIGURE_ARGS+=	--with-ssl=openssl

PKGCONFIG_OVERRIDE+=	loudmouth-1.0.pc.in

# https://github.com/mcabber/loudmouth/issues/42
BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
