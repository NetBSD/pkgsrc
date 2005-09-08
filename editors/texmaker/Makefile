# $NetBSD: Makefile,v 1.1.1.1 2005/09/08 19:59:13 drochner Exp $

DISTNAME=	texmaker-1.12
CATEGORIES=	editors
MASTER_SITES=	http://www.xm1math.net/texmaker/
MASTER_SITES+=	http://www.epidauros.be/pkgsrc/	### TEMPORARY!
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	geert.hendrickx@ua.ac.be
HOMEPAGE=	http://www.xm1math.net/texmaker/
COMMENT=	LaTeX editor and front end

USE_LIBTOOL=	yes

post-configure:
	cd ${WRKSRC} && \
	${QTDIR}/bin/qmake -unix PREFIX=${PREFIX} texmaker.pro

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt3-tools=	build
.include "../../mk/bsd.pkg.mk"
