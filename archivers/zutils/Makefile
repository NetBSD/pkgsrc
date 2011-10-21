# $NetBSD: Makefile,v 1.1.1.1 2011/10/21 21:41:09 ryoon Exp $
#

DISTNAME=	zutils-0.9
CATEGORIES=	archivers
MASTER_SITES=	http://download.savannah.gnu.org/releases/zutils/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/zutils/zutils.html
COMMENT=	Utilities able to deal with any combination of compressed and non-compressed files
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--infodir=${PREFIX}/info
USE_LANGUAGES=		c++

INFO_FILES=		yes

.include "../../mk/bsd.pkg.mk"
