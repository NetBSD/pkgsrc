# $NetBSD: Makefile,v 1.1.1.1 1999/11/25 08:17:15 sakamoto Exp $
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

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

USE_GMAKE=	yes
USE_MOTIF=	yes
MAKE_ENV+=	MOTIF_DEFS="${MOTIF_DEFS}" GMAKE="${GMAKE}"

post-extract:
	${GTAR} -C ${WRKSRC}/combo -xzf ${DISTDIR}/ileaf-widgets.tar.Z

post-install:
	${GTAR} -C ${PREFIX}/libexec/Ngraph -xzf ${DISTDIR}/Ngraph-6.3-doc.tar.gz

.include "../../mk/bsd.pkg.mk"

.if !defined(IS_LESSTIF) || (${IS_LESSTIF} != "0")
MOTIF_DEFS=	-DMOTIF12
.endif
