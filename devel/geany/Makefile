# $NetBSD: Makefile,v 1.1.1.1 2007/02/07 19:32:03 rmind Exp $

DISTNAME=	geany-0.10
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=geany/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://geany.uvena.de/
COMMENT=	Geany integrated development environment (IDE)

GNU_CONFIGURE=	YES
USE_TOOLS+=		pkg-config
USE_LANGUAGES=	c c++

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
