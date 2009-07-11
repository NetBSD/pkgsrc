# $NetBSD: Makefile,v 1.6 2009/07/11 08:05:06 obache Exp $
#

DISTNAME=		ocrad-0.18
CATEGORIES=		graphics
MASTER_SITES=		http://ftp.gnu.org/gnu/ocrad/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/ocrad/ocrad.html
COMMENT=		GNU OCR (Optical Character Recognition) program
LICENSE=		gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c++
USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--infodir=${PREFIX}/${PKGINFODIR}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
INFO_FILES=		yes

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
