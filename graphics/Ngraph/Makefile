# $NetBSD: Makefile,v 1.19 2005/12/12 21:36:55 joerg Exp $
#

DISTNAME=	Ngraph-6.3.30-src
PKGREVISION=	1
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	graphics
MASTER_SITES=	http://www2e.biglobe.ne.jp/~isizaka/bin/ \
		ftp://ftp.cs.umb.edu/pub/interleaf/CDE/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} Ngraph-6.3.30-doc.tar.gz \
		ileaf-widgets.tar.Z

MAINTAINER=	oishi@ims.ac.jp
HOMEPAGE=	http://www2e.biglobe.ne.jp/~isizaka/
COMMENT=	The 2D graph and data analysis program

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

USE_TOOLS+=		gmake gtar

post-extract:
	${GTAR} -C ${WRKSRC}/combo -xzf ${DISTDIR}/ileaf-widgets.tar.Z

post-install:
	${GTAR} -C ${PREFIX}/libexec/Ngraph -xzf ${DISTDIR}/Ngraph-6.3.30-doc.tar.gz

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
