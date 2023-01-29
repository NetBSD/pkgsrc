# $NetBSD: Makefile,v 1.17 2023/01/29 21:14:26 ryoon Exp $
#

DISTNAME=	grantlee-0.5.1
PKGREVISION=	9
CATEGORIES=	devel
MASTER_SITES=	http://downloads.grantlee.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.gitorious.org/grantlee/pages/Home
COMMENT=	String template engine in QT based on Django template system
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	c c++
USE_CMAKE=	yes

SUBST_CLASSES+=		fix-inc
SUBST_STAGE.fix-inc=	pre-configure
SUBST_MESSAGE.fix-inc=	Fixing install dir for includes
SUBST_FILES.fix-inc+=	CMakeLists.txt
SUBST_SED.fix-inc+=	-e 's,INCLUDE_INSTALL_DIR include,INCLUDE_INSTALL_DIR include/grantlee-qt4,'

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
