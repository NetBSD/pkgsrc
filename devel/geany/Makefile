# $NetBSD: Makefile,v 1.2 2007/02/07 22:12:21 rillig Exp $

DISTNAME=	geany-0.10
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=geany/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://geany.uvena.de/
COMMENT=	Geany integrated development environment (IDE)

GNU_CONFIGURE=	YES
USE_TOOLS+=		pkg-config
USE_LANGUAGES=	c c++

BUILDLINK_TRANSFORM+=	rm:-lstdc++
MAKE_FLAGS+=		CCLD=${CXX:Q}

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
