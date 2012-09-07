# $NetBSD: Makefile,v 1.27 2012/09/07 19:16:32 adam Exp $

DISTNAME=	texmaker-1.8
PKGREVISION=	12
CATEGORIES=	editors
MASTER_SITES=	http://www.xm1math.net/texmaker/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ghen@NetBSD.org
HOMEPAGE=	http://www.xm1math.net/texmaker/
COMMENT=	LaTeX editor and front end

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c++
USE_LIBTOOL=	yes

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

do-configure:
	cd ${WRKSRC} && env ${CONFIGURE_ENV} \
	${QTDIR}/bin/qmake -unix PREFIX=${PREFIX} texmaker.pro

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
