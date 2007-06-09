# $NetBSD: Makefile,v 1.2 2007/06/09 10:46:01 rillig Exp $
#

DISTNAME=		qconf-1.3
CATEGORIES=		devel
MASTER_SITES=		http://delta.affinix.com/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rillig@NetBSD.org
HOMEPAGE=		http://delta.affinix.com/qconf/
COMMENT=		Configure script generator for qmake

USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
USE_LANGUAGES=		c c++

.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
