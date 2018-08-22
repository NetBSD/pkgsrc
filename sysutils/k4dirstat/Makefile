# $NetBSD: Makefile,v 1.44 2018/08/22 09:46:35 wiz Exp $

DISTNAME=	k4dirstat-2.7.8
PKGREVISION=	14
CATEGORIES=	sysutils
MASTER_SITES=	https://bitbucket.org/jeromerobert/k4dirstat/get/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	https://bitbucket.org/jeromerobert/k4dirstat
COMMENT=	Graphical disk usage utility

BUILD_DEPENDS+=	automoc4>=0.9.87:../../devel/automoc4

USE_TOOLS+=	perl msgfmt
USE_LANGUAGES=	c c++

WRKSRC=		${WRKDIR}/jeromerobert-k4dirstat-3a4663ee20e7

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kde-baseapps4/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../mk/bsd.pkg.mk"
