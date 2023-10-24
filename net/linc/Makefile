# $NetBSD: Makefile,v 1.48 2023/10/24 22:10:24 wiz Exp $

DISTNAME=		linc-1.1.1
PKGREVISION=		18
CATEGORIES=		net gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/linc/1.1/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.gnome.org/
COMMENT=		Network client/server library

CONFLICTS=		ORBit2>=2.8

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

PKGCONFIG_OVERRIDE=	linc.pc.in

CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--with-openssl

.include "../../devel/glib2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
