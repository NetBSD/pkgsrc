# $NetBSD: Makefile,v 1.24 2012/10/06 14:10:40 asau Exp $
#

DISTNAME=	Ngraph-6.3.30-src
PKGREVISION=	3
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	graphics
MASTER_SITES=	http://www2e.biglobe.ne.jp/~isizaka/bin/ \
		ftp://ftp.cs.umb.edu/pub/interleaf/CDE/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} Ngraph-6.3.30-doc.tar.gz \
		ileaf-widgets.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www2e.biglobe.ne.jp/~isizaka/
COMMENT=	The 2D graph and data analysis program

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

USE_TOOLS+=		gmake gtar

INSTALLATION_DIRS+=	bin

post-extract:
	${GTAR} -C ${WRKSRC}/combo -xzf ${DISTDIR}/ileaf-widgets.tar.Z

post-install:
	${GTAR} -C ${DESTDIR}${PREFIX}/libexec/Ngraph -xzf ${DISTDIR}/Ngraph-6.3.30-doc.tar.gz

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
