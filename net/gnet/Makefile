# $NetBSD: Makefile,v 1.10 2003/05/02 11:56:03 wiz Exp $
#

DISTNAME=		gnet-2.0.1
PKGREVISION=	1
CATEGORIES=		net
MASTER_SITES=		http://www.gnetlibrary.org/src/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnetlibrary.org/
COMMENT=		simple network library

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/gnet.pc.in
GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
CONFIGURE_ARGS=		--enable-glib2
TEST_TARGET=		check

.include "../../devel/glib2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
