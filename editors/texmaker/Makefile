# $NetBSD: Makefile,v 1.8 2006/03/02 15:09:49 ghen Exp $

DISTNAME=	texmaker-1.3
CATEGORIES=	editors
MASTER_SITES=	http://www.xm1math.net/texmaker/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ghen@NetBSD.org
HOMEPAGE=	http://www.xm1math.net/texmaker/
COMMENT=	LaTeX editor and front end

USE_LIBTOOL=	yes

do-configure:
	cd ${WRKSRC} && \
	${SETENV} ${CONFIGURE_ENV} \
	${QTDIR:Q}/bin/qmake -unix PREFIX=${PREFIX:Q} texmaker.pro

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
