# $NetBSD: Makefile,v 1.9 2024/05/29 16:31:39 adam Exp $

DISTNAME=	anymeal-1.18
PKGREVISION=	7
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=wedesoft/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wedesoft.github.io/anymeal
COMMENT=	Free and open source recipe management software
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
CONFIGURE_ENV+=	GTEST=${PREFIX}/include

PREPEND_PATH+=	${QTDIR}/bin

# work around broken qt link test
CONFIGURE_ARGS+=	ax_cv_qt_test_result=yes

.include "../../converters/recode/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
#.include "../../devel/googletest/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtserialport/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
