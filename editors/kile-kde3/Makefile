# $NetBSD: Makefile,v 1.21 2014/01/01 11:52:14 wiz Exp $

DISTNAME=		kile-2.0.2
PKGREVISION=		31
CATEGORIES=		editors kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kile/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://kile.sourceforge.net/
COMMENT=		LaTeX source editor - TeX shell - Gnuplot front end

USE_TOOLS+=		gmake perl msgfmt
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

REPLACE_PERL=		src/kile1.6_upd.pl \
			src/kile1.7_upd.pl \
			src/kile1.9_upd.pl \
			src/kile1.9-1_upd.pl \
			src/kile2.0-1_upd.pl \
			src/kile2.0-2_upd.pl \
			src/kile2.0-3_upd.pl \
			src/kile2.0-4_upd.pl \
			src/kile2.0-5_upd.pl

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/kdegraphics3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
