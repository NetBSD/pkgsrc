# $NetBSD: Makefile,v 1.30 2005/12/05 20:50:46 rillig Exp $
#

DISTNAME=		gnet-2.0.7
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		http://www.gnetlibrary.org/src/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnetlibrary.org/
COMMENT=		Simple network library

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE=	gnet-2.0.pc.in
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-glib2
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc
TEST_TARGET=		check

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
