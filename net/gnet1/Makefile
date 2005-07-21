# $NetBSD: Makefile,v 1.17 2005/07/21 16:29:55 wiz Exp $
#

DISTNAME=		gnet-1.1.8
PKGNAME=		gnet1-1.1.8
PKGREVISION=		3
CATEGORIES=		net
MASTER_SITES=		http://www.gnetlibrary.org/src/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnetlibrary.org/
COMMENT=		Simple network library (older version)

CONFLICTS=		gnet<=1.1.8

USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE=	gnet.pc.in
GNU_CONFIGURE=		YES
CONFIGURE_ARGS=		--enable-glib2
TEST_TARGET=		check

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkg-config/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
