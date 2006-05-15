# $NetBSD: Makefile,v 1.1.1.1 2006/05/15 11:19:24 rillig Exp $
#

DISTNAME=		qconf-1.2
CATEGORIES=		devel
MASTER_SITES=		http://delta.affinix.com/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rillig@NetBSD.org
HOMEPAGE=		http://delta.affinix.com/download/
COMMENT=		Configure script generator for qmake

USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
USE_LANGUAGES=		c c++

.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
