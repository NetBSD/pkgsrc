# $NetBSD: Makefile,v 1.3 2002/12/24 06:09:59 wiz Exp $

DISTNAME=		kile-1.3
PKGREVISION=		1
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
