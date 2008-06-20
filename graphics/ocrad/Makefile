# $NetBSD: Makefile,v 1.5 2008/06/20 01:09:22 joerg Exp $
#

DISTNAME=		ocrad-0.13
CATEGORIES=		graphics
MASTER_SITES=		http://ftp.gnu.org/gnu/ocrad/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/ocrad/ocrad.html
COMMENT=		GNU OCR (Optical Character Recognition) program

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c++
USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--infodir=${PREFIX:Q}/${PKGINFODIR:Q}
CONFIGURE_ARGS+=	--mandir=${PREFIX:Q}/${PKGMANDIR:Q}
INFO_FILES=		# PLIST

.include "../../mk/bsd.pkg.mk"
