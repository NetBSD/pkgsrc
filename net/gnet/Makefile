# $NetBSD: Makefile,v 1.4 2002/10/30 03:09:36 rh Exp $
#

DISTNAME=		gnet-1.1.7
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

.include "../../devel/glib2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
