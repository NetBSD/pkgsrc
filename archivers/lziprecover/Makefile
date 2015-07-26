# $NetBSD: Makefile,v 1.6 2015/07/26 12:17:47 mef Exp $

DISTNAME=	lziprecover-1.17
CATEGORIES=	archivers
MASTER_SITES=	http://download.savannah.gnu.org/releases/lzip/lziprecover/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/lzip/lziprecover.html
COMMENT=	Recovery tool for lossless data compressor based on the LZMA algorithm
LICENSE=	gnu-gpl-v2 # or later

USE_LANGUAGES=		c++
HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		--prefix=${PREFIX}
CONFIGURE_ARGS+=	--infodir=${PREFIX}/${PKGINFODIR}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
INFO_FILES=		YES

.include "../../mk/bsd.pkg.mk"
