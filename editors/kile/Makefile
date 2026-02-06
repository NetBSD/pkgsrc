# $NetBSD: Makefile,v 1.172 2026/02/06 10:04:39 wiz Exp $

DISTNAME=		kile-2.9.94
PKGREVISION=		3
CATEGORIES=		editors kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kile/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		markd@NetBSD.org
HOMEPAGE=		https://kile.sourceforge.io/
COMMENT=		LaTeX source editor - TeX shell - Gnuplot front end

TOOL_DEPENDS+=		kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=		perl msgmerge pkg-config

REPLACE_PERL=		kile1.6_upd.pl \
			kile1.7_upd.pl \
			kile1.9_upd.pl \
			kile1.9-1_upd.pl \
			kile2.0-1_upd.pl \
			kile2.0-2_upd.pl \
			kile2.0-3_upd.pl \
			kile2.0-4_upd.pl \
			kile2.0-5_upd.pl

.include "../../meta-pkgs/kde/applications.mk"

.include "../../devel/kf6-ktexteditor/buildlink3.mk"
.include "../../devel/qt6-qt5compat/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../print/okular/buildlink3.mk"
.include "../../print/poppler-qt6/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
