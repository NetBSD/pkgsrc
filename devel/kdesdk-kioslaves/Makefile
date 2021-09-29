# $NetBSD: Makefile,v 1.58 2021/09/29 19:00:31 adam Exp $

DISTNAME=	kdesdk-kioslaves-${_KDE_VERSION}
PKGREVISION=	45
CATEGORIES=	devel
COMMENT=	KIO-Slaves for subversion and perldoc

.include "../../meta-pkgs/kde4/Makefile.kde4"

REPLACE_PERL+= \
	perldoc/pod2html.pl

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../devel/subversion-base/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
