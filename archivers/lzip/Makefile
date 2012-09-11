# $NetBSD: Makefile,v 1.6 2012/09/11 19:46:56 asau Exp $
#

DISTNAME=	lzip-1.13
CATEGORIES=	archivers
MASTER_SITES=	http://download.savannah.gnu.org/releases/lzip/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/lzip/lzip.html
COMMENT=	Lossless data compressor based on the LZMA algorithm
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c++
HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		--prefix=${PREFIX}
CONFIGURE_ARGS+=	--infodir=${PREFIX}/${PKGINFODIR}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
INFO_FILES=		YES

.include "../../mk/bsd.pkg.mk"
