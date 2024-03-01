# $NetBSD: Makefile,v 1.11 2024/03/01 06:34:44 kim Exp $

DISTNAME=	ocrad-0.21
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNU:=ocrad/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/ocrad/ocrad.html
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
