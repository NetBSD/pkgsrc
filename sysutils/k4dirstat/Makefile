# $NetBSD: Makefile,v 1.1.1.1 2012/03/21 23:21:20 markd Exp $

DISTNAME=	k4dirstat-2.7.3
CATEGORIES=	sysutils
MASTER_SITES=	http://bitbucket.org/jeromerobert/k4dirstat/get/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://bitbucket.org/jeromerobert/k4dirstat
COMMENT=	Graphical disk usage utility

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	automoc4>=0.9.87:../../devel/automoc4

USE_TOOLS+=	perl msgfmt
USE_LANGUAGES=	c c++

WRKSRC=		${WRKDIR}/jeromerobert-k4dirstat-7764f6508187

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kde-baseapps4/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
