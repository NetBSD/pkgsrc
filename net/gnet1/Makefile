# $NetBSD: Makefile,v 1.2 2003/04/15 12:17:19 wiz Exp $
#

DISTNAME=		gnet-1.1.8
PKGNAME=		gnet1-1.1.8
CATEGORIES=		net
MASTER_SITES=		http://www.gnetlibrary.org/src/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnetlibrary.org/
COMMENT=		simple network library

CONFLICTS=		gnet<=1.1.8

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/gnet.pc.in
GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
CONFIGURE_ARGS=		--enable-glib2
TEST_TARGET=		check

.include "../../devel/glib2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
