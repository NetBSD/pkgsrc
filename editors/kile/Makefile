# $NetBSD: Makefile,v 1.21 2004/04/14 16:15:22 jmmv Exp $

DISTNAME=		kile-1.6.2
CATEGORIES=		editors kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kile/}

MAINTAINER=		markd@NetBSD.org
HOMEPAGE=		http://kile.sourceforge.net/
COMMENT=		LaTeX source editor - TeX shell - Gnuplot front end

USE_BUILDLINK2=		yes
USE_DIRS+=		xdg-1.1
USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

.include "../../graphics/kdegraphics3/buildlink2.mk"
.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdelibs3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
