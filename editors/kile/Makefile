# $NetBSD: Makefile,v 1.5 2003/05/02 11:54:45 wiz Exp $

DISTNAME=		kile-1.32
PKGREVISION=		1
CATEGORIES=		editors kde
MASTER_SITES=		http://perso.club-internet.fr/pascal.brachet/kile/

MAINTAINER=		markd@netbsd.org
HOMEPAGE=		http://perso.club-internet.fr/pascal.brachet/kile/index.html
COMMENT=		LaTeX source editor - TeX shell - Gnuplot front end

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes

.include "../../graphics/kdegraphics3/buildlink2.mk"
.include "../../x11/kde3/buildlink2.mk"
.include "../../x11/kdelibs3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
