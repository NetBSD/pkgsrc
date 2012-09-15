# $NetBSD: Makefile,v 1.38 2012/09/15 10:05:59 obache Exp $
#

DISTNAME=		gnet-2.0.8
PKGREVISION=		4
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnet/2.0/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnetlibrary.org/
COMMENT=		Simple network library

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE=	gnet-2.0.pc.in
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc
TEST_TARGET=		check

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
