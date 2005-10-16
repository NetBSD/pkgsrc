# $NetBSD: Makefile,v 1.1.1.1 2005/10/16 20:17:49 wiz Exp $
#

DISTNAME=		ocrad-0.13
CATEGORIES=		graphics
MASTER_SITES=		http://ftp.gnu.org/gnu/ocrad/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/ocrad/ocrad.html
COMMENT=		GNU OCR (Optical Character Recognition) program

USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--mandir=${PREFIX:Q}/${PKGMANDIR:Q}
CONFIGURE_ARGS+=	--infodir=${PREFIX:Q}/${INFO_DIR:Q}

INFO_FILES=		ocrad.info

.include "../../mk/bsd.pkg.mk"
