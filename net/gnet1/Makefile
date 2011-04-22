# $NetBSD: Makefile,v 1.23 2011/04/22 13:42:16 obache Exp $
#

DISTNAME=		gnet-1.1.8
PKGNAME=		gnet1-1.1.8
PKGREVISION=		5
CATEGORIES=		net
MASTER_SITES=		http://www.gnetlibrary.org/src/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnetlibrary.org/
COMMENT=		Simple network library (older version)

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		gnet<=1.1.8

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE=	gnet.pc.in
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-glib2
TEST_TARGET=		check

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
