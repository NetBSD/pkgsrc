# $NetBSD: Makefile,v 1.18 2003/07/30 13:49:47 wiz Exp $
#

DISTNAME=		gnet-2.0.4
CATEGORIES=		net
MASTER_SITES=		http://www.gnetlibrary.org/src/

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.gnetlibrary.org/
COMMENT=		Simple network library

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/gnet.pc.in
GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
CONFIGURE_ARGS=		--enable-glib2
TEST_TARGET=		check

.include "../../devel/glib2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
