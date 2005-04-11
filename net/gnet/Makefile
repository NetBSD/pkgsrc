# $NetBSD: Makefile,v 1.26 2005/04/11 21:46:47 tv Exp $
#

DISTNAME=		gnet-2.0.7
CATEGORIES=		net
MASTER_SITES=		http://www.gnetlibrary.org/src/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnetlibrary.org/
COMMENT=		Simple network library

USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE=	gnet-2.0.pc.in
GNU_CONFIGURE=		YES
CONFIGURE_ARGS=		--enable-glib2
TEST_TARGET=		check

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
