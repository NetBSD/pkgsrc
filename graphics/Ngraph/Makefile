# $NetBSD: Makefile,v 1.11 2004/04/24 23:25:43 snj Exp $
#

DISTNAME=	Ngraph-6.3.20-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	graphics
MASTER_SITES=	http://www2e.biglobe.ne.jp/~isizaka/bin/ \
		ftp://ftp.cs.umb.edu/pub/interleaf/CDE/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} Ngraph-6.3-doc.tar.gz \
		ileaf-widgets.tar.Z

MAINTAINER=	oishi@ims.ac.jp
HOMEPAGE=	http://www2e.biglobe.ne.jp/~isizaka/
COMMENT=	The 2D graph and data analysis program

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

USE_BUILDLINK3=		yes
USE_X11=		yes
USE_GNU_TOOLS+=		make

post-extract:
	${GTAR} -C ${WRKSRC}/combo -xzf ${DISTDIR}/ileaf-widgets.tar.Z

post-install:
	${GTAR} -C ${PREFIX}/libexec/Ngraph -xzf ${DISTDIR}/Ngraph-6.3-doc.tar.gz

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
