# $NetBSD: Makefile,v 1.3 2004/10/03 00:14:54 tv Exp $
#

DISTNAME=	kphotools-0.2.1
PKGREVISION=	2
CATEGORIES=	kde graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kphotools/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ianzag@mail.ru
HOMEPAGE=	http://kphotools.sourceforge.net/
COMMENT=	KDE app which helps you creating fast online photo galleries in HTML

USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
USE_LANGUAGES=	c c++
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

SUBST_CLASSES+=		kphotools
SUBST_MESSAGE.kphotools=	"Fixing /usr/share path."
SUBST_FILES.kphotools=	src/GalleryThrd.cpp src/LogoWid.cpp src/LogoWid.ui src/StyleWid.ui.h
SUBST_SED.kphotools=	-e 's|@kphotoolsdir@|${KDEDIR}/share/kde/apps/kphotools|'
SUBST_STAGE.kphotools=	post-patch

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
