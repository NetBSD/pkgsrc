# $NetBSD: Makefile,v 1.2 2010/01/24 23:59:33 zafer Exp $
#

DISTNAME=	lzip-1.7
CATEGORIES=	archivers
MASTER_SITES=	http://download.savannah.gnu.org/releases/lzip/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/lzip/lzip.html
COMMENT=	Lossless data compressor based on the LZMA algorithm
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c++
HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		--prefix=${PREFIX}
CONFIGURE_ARGS+=	--infodir=${PREFIX}/info
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
INFO_FILES=		YES

.include "../../mk/bsd.pkg.mk"
