# $NetBSD: Makefile,v 1.16 2004/02/09 11:06:06 markd Exp $

DISTNAME=		kile-1.6.1
CATEGORIES=		editors kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kile/}

MAINTAINER=		markd@NetBSD.org
HOMEPAGE=		http://kile.sourceforge.net/
COMMENT=		LaTeX source editor - TeX shell - Gnuplot front end

USE_BUILDLINK2=		yes
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes

.include "../../graphics/kdegraphics3/buildlink2.mk"
.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdelibs3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
