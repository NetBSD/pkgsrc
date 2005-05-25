# $NetBSD: Makefile,v 1.27 2005/05/25 11:41:32 wiz Exp $
#

DISTNAME=		gnet-2.0.7
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		http://www.gnetlibrary.org/src/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnetlibrary.org/
COMMENT=		Simple network library

USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE=	gnet-2.0.pc.in
GNU_CONFIGURE=		YES
CONFIGURE_ARGS=		--enable-glib2
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc
TEST_TARGET=		check

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
