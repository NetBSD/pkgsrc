# $NetBSD: Makefile,v 1.7 2002/09/22 00:06:23 jlam Exp $
#

DISTNAME=	Ngraph-6.3.06-src
PKGNAME=	Ngraph-6.3.06
CATEGORIES=	graphics
MASTER_SITES=	http://www2e.biglobe.ne.jp/~isizaka/bin/ \
		ftp://ftp.cs.umb.edu/pub/interleaf/CDE/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} Ngraph-6.3-doc.tar.gz \
		ileaf-widgets.tar.Z

MAINTAINER=	oishi@ims.ac.jp
HOMEPAGE=	http://www2e.biglobe.ne.jp/~isizaka/
COMMENT=	the 2D graph and data analysis program

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

USE_BUILDLINK2=		yes
USE_X11BASE=		yes
USE_GMAKE=		yes

post-extract:
	${GTAR} -C ${WRKSRC}/combo -xzf ${DISTDIR}/ileaf-widgets.tar.Z

post-install:
	${GTAR} -C ${PREFIX}/libexec/Ngraph -xzf ${DISTDIR}/Ngraph-6.3-doc.tar.gz

.include "../../mk/motif.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
