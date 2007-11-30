# $NetBSD: Makefile,v 1.44 2007/11/30 21:55:05 wiz Exp $

DISTNAME=		kile-1.9.3
PKGREVISION=		4
CATEGORIES=		editors kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kile/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		markd@NetBSD.org
HOMEPAGE=		http://kile.sourceforge.net/
COMMENT=		LaTeX source editor - TeX shell - Gnuplot front end

USE_TOOLS+=		gmake perl msgfmt
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

REPLACE_PERL=		src/kile1.6_upd.pl \
			src/kile1.7_upd.pl \
			src/kile1.9_upd.pl \
			src/kile1.9-1_upd.pl

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/kdegraphics3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
