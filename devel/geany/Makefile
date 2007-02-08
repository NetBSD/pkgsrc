# $NetBSD: Makefile,v 1.3 2007/02/08 00:25:13 rillig Exp $

DISTNAME=	geany-0.10
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=geany/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://geany.uvena.de/
COMMENT=	Geany integrated development environment (IDE)

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
MAKE_FLAGS+=		CCLD=${CXX:Q}
BUILDLINK_TRANSFORM+=	rm:-lstdc++

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
