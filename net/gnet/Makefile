# $NetBSD: Makefile,v 1.2 2002/08/25 21:49:57 jlam Exp $
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
USE_BUILDLINK2=		YES

.include "../../devel/glib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
