# $NetBSD: Makefile,v 1.25 2013/03/15 20:58:31 wiz Exp $
#

DISTNAME=	keepassx-0.4.3
PKGREVISION=	3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=keepassx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.keepassx.org/
COMMENT=	Password manager or safe
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
	${CP} ${WRKSRC}/bin/keepassx ${WRKSRC}/src

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
