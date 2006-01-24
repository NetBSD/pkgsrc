# $NetBSD: Makefile,v 1.5 2006/01/24 07:32:06 wiz Exp $

DISTNAME=	texmaker-1.12
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://www.xm1math.net/texmaker/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ghen@NetBSD.org
HOMEPAGE=	http://www.xm1math.net/texmaker/
COMMENT=	LaTeX editor and front end

USE_LIBTOOL=	yes

post-configure:
	cd ${WRKSRC} && \
	${QTDIR}/bin/qmake -unix PREFIX=${PREFIX} texmaker.pro

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
