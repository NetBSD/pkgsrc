# $NetBSD: Makefile,v 1.1.1.1 2012/03/14 14:40:36 wiz Exp $

DISTNAME=	lziprecover-1.13
CATEGORIES=	archivers
MASTER_SITES=	http://download.savannah.gnu.org/releases/lzip/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/lzip/lziprecover.html
COMMENT=	Recovery tool for lossless data compressor based on the LZMA algorithm
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c++
HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		--prefix=${PREFIX}
CONFIGURE_ARGS+=	--infodir=${PREFIX}/${PKGINFODIR}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
INFO_FILES=		YES

.include "../../mk/bsd.pkg.mk"
