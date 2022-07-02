# $NetBSD: Makefile,v 1.131 2022/07/02 16:53:14 ryoon Exp $

DISTNAME=		kile-2.9.93
PKGREVISION=		8
CATEGORIES=		editors kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kile/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		markd@NetBSD.org
HOMEPAGE=		https://kile.sourceforge.io/
COMMENT=		LaTeX source editor - TeX shell - Gnuplot front end

BUILD_DEPENDS+=		kdoctools>=5.19.0:../../devel/kdoctools
DEPENDS+=		kinit>=5.19.0:../../x11/kinit

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

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	pre-configure
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	src/CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_XDG_EX_DIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/kile.categories \
		${PKG_SYSCONFDIR}/xdg/kile.categories

.include "../../meta-pkgs/kde/applications.mk"

.include "../../devel/ktexteditor/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../print/okular/buildlink3.mk"
.include "../../print/poppler-qt5/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/khtml/buildlink3.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
