# $NetBSD: Makefile,v 1.18 2005/08/10 20:56:22 jlam Exp $
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

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE=	gnet.pc.in
GNU_CONFIGURE=		YES
CONFIGURE_ARGS=		--enable-glib2
TEST_TARGET=		check

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
