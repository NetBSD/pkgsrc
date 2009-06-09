# $NetBSD: Makefile,v 1.28 2009/06/09 21:31:04 minskim Exp $

DISTNAME=	dvipdfm-0.13.2d
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://gaspra.kettering.edu/dvipdfm/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://gaspra.kettering.edu/dvipdfm/
COMMENT=	DVI driver to product PDF directly

CONFLICTS+=	teTeX-bin<=3.0nb27
DEPENDS+=	tex-bin-dvipdfm-[0-9]*:../../print/tex-bin-dvipdfm

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${PKGBASE}
GNU_CONFIGURE=	yes

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}
INSTALL_MAKE_FLAGS+=	mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
