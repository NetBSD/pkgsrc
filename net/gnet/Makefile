# $NetBSD: Makefile,v 1.14 2003/06/02 01:17:59 jschauma Exp $
#

DISTNAME=		gnet-2.0.3
CATEGORIES=		net
MASTER_SITES=		http://www.gnetlibrary.org/src/

MAINTAINER=		tech-pkg@netbsd.org
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
