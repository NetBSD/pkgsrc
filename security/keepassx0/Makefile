# $NetBSD: Makefile,v 1.2 2016/03/05 11:29:21 jperkin Exp $

DISTNAME=	keepassx-0.4.4
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://www.keepassx.org/releases/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.keepassx.org/
COMMENT=	Password manager or safe v0.4 (kdb support)
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_LIBTOOL=	YES

QMAKE=			${QTDIR}/bin/qmake
CONFIGURE_ARGS+=	QMAKE=${QMAKE:Q} PREFIX=${PREFIX:Q} PRECOMPILED=0
MAKE_ENV+=		QTDIR=${QTDIR} PREFIX=${PREFIX}
INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

do-configure:
	cd ${WRKSRC} && \
		${QMAKE} -unix -o Makefile ${CONFIGURE_ARGS} keepassx.pro

pre-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/keepassx ${WRKSRC}/src

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
