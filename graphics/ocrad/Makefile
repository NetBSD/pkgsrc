# $NetBSD: Makefile,v 1.7 2010/03/08 12:35:54 adam Exp $

DISTNAME=	ocrad-0.19
CATEGORIES=	graphics
MASTER_SITES=	http://ftp.gnu.org/gnu/ocrad/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/ocrad/ocrad.html
COMMENT=	GNU OCR (Optical Character Recognition) program

LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

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
