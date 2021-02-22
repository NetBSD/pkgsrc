# $NetBSD: Makefile,v 1.1 2021/02/22 19:45:08 fcambus Exp $

DISTNAME=	lunzip-1.12
CATEGORIES=	archivers
MASTER_SITES=	https://download.savannah.gnu.org/releases/lzip/lunzip/

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://www.nongnu.org/lzip/lunzip.html
COMMENT=	Decompressor for the lzip format
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=	yes

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
