# $NetBSD: Makefile,v 1.9 2012/10/06 14:11:08 asau Exp $

DISTNAME=	ocrad-0.21
CATEGORIES=	graphics
MASTER_SITES=	http://ftp.gnu.org/gnu/ocrad/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/ocrad/ocrad.html
COMMENT=	GNU OCR (Optical Character Recognition) program

LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c++
USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--infodir=${PREFIX}/${PKGINFODIR}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ENV+=		CXXFLAGS=${CXXFLAGS:Q}
INFO_FILES=		yes

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
