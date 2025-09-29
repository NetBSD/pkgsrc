# $NetBSD: Makefile,v 1.1 2025/09/29 14:08:53 ryoon Exp $

DISTNAME=	xmagv111
PKGNAME=	xmagv-1.11
CATEGORIES=	graphics
MASTER_SITES=	https://ftp.vector.co.jp/02/87/1315/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www2s.biglobe.ne.jp/yav/soft/
COMMENT=	Viewer for MAG graphics format
LICENSE=	public-domain

WRKSRC=		${WRKDIR}/xmagv
HAS_CONFIGURE=	yes
USE_IMAKE=	yes

CONFIGURE_ARGS+=	--prefix=${PREFIX}

#LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib


.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
