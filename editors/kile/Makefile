# $NetBSD: Makefile,v 1.1.1.1 2002/10/05 05:53:58 markd Exp $

DISTNAME=		kile-1.2
CATEGORIES=		editors kde
MASTER_SITES=		http://xm1.net.free.fr/kile/

MAINTAINER=		markd@netbsd.org
HOMEPAGE=		http://xm1.net.free.fr/kile/index.html
COMMENT=		LaTeX source editor - TeX shell - Gnuplot front end

USE_BUILDLINK2=		YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES

.include "../../graphics/kdegraphics3/buildlink2.mk"
.include "../../x11/kde3/buildlink2.mk"
.include "../../x11/kdelibs3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
