# $NetBSD: Makefile,v 1.45 2014/11/27 15:32:38 wiz Exp $

DISTNAME=		kchmviewer-7.1
CATEGORIES=		misc x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kchmviewer/}

MAINTAINER=		ianzag@mail.ru
HOMEPAGE=		http://www.kchmviewer.net/
COMMENT=		CHM (MS HTML help file format) viewer
LICENSE=		gnu-gpl-v3

USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=	YES
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES

SUBST_CLASSES+=		zip
SUBST_SED.zip+=		-e 's,-I${PREFIX}/include,-I${PREFIX}/include -I${PREFIX}/lib/libzip/include,'
SUBST_MESSAGE.zip=	Add missing header search path.
SUBST_FILES.zip+=	lib/libebook/Makefile
SUBST_STAGE.zip=	post-configure

.include "options.mk"

.include "../../devel/chmlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.qt4-libs+=	qt4-libs>=4.5.0
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../archivers/libzip/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
