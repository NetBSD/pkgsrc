# $NetBSD: Makefile,v 1.5 2013/04/06 03:45:06 rodent Exp $
#

DISTNAME=	zutils-0.9
CATEGORIES=	archivers
MASTER_SITES=	http://download.savannah.gnu.org/releases/zutils/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/zutils/zutils.html
COMMENT=	Utilities for any combination of compressed and non-compressed files
LICENSE=	gnu-gpl-v3

CONFLICTS=		lzip<1.12

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--infodir=${PREFIX}/${PKGINFODIR}
USE_LANGUAGES=		c++

INFO_FILES=		yes

.include "../../mk/bsd.pkg.mk"
