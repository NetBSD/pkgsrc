# $NetBSD: Makefile,v 1.2 2020/11/05 09:08:14 ryoon Exp $

DISTNAME=	q5go-1.1.1
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=bernds/}
GITHUB_PROJECT=	q5Go
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bernds/q5Go/
COMMENT=	Tool for Go players
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c++

CONFIGURE_DIRS=	build

MAKE_ENV+=	INSTALL_ROOT=${DESTDIR}

do-configure:
	${MKDIR} ${WRKSRC}/build
	cd ${WRKSRC}/build && ${SETENV} ${MAKE_ENV} ${QTDIR}/bin/qmake ../src/q5go.pro PREFIX=${PREFIX}

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
