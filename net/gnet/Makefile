# $NetBSD: Makefile,v 1.44 2025/10/23 20:38:44 wiz Exp $
#

DISTNAME=		gnet-2.0.8
PKGREVISION=		7
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnet/2.0/}

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		https://live.gnome.org/GNetLibrary
COMMENT=		Simple network library

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE=	gnet-2.0.pc.in
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc
TEST_TARGET=		check

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
