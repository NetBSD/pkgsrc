# $NetBSD: Makefile,v 1.1.1.1 2002/05/16 18:13:26 wiz Exp $
#

DISTNAME=	gnet-1.1.4
CATEGORIES=	net
MASTER_SITES=	http://www.gnetlibrary.org/src/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnetlibrary.org/
COMMENT=	simple network library

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		YES
USE_BUILDLINK_ONLY=	YES

.include "../../devel/glib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
