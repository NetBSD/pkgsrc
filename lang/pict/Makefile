# $NetBSD: Makefile,v 1.18 2018/04/13 13:55:34 jaapb Exp $

DISTNAME=	pict-4.1
PKGREVISION=	14
CATEGORIES=	lang
MASTER_SITES=	http://www.cis.upenn.edu/~bcpierce/papers/pict/pict-4.1/

PATCH_SITES=	http://www.NetBSD.org/~dholland/patchkits/pict/
PATCHFILES=	pict-jumbo-patch-20180316.gz
PATCH_DIST_STRIP= -p1

MAINTAINER=	dholland@NetBSD.org
HOMEPAGE=	http://www.cis.upenn.edu/~bcpierce/papers/pict/Html/Pict.html
COMMENT=	Concurrent language based on Milner's pi calculus
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=		no

USE_TOOLS+=		gmake
INSTALLATION_DIRS+=	bin lib/pict share/doc/pict

MAKE_ENV+=		X11INCLUDE=${X11BASE}/include \
			X11LIB=${X11BASE}/lib

TEST_TARGET=	test

.include "../../mk/ocaml.mk"

.if !empty(OCAML_USE_OPT_COMPILER:Myes)
MAKE_ENV+=		OCAMLOPT=yes
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/Doc/*.ps ${DESTDIR}${PREFIX}/share/doc/pict/

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
