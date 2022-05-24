# $NetBSD: Makefile,v 1.24 2022/05/24 18:51:53 jaapb Exp $

DISTNAME=	pict-4.1
PKGREVISION=	18
CATEGORIES=	lang
MASTER_SITES=	http://www.cis.upenn.edu/~bcpierce/papers/pict/pict-4.1/

PATCH_SITES=		http://www.NetBSD.org/~dholland/patchkits/pict/
PATCHFILES=		pict-jumbo-patch-20180316.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	dholland@NetBSD.org
HOMEPAGE=	https://www.cis.upenn.edu/~bcpierce/papers/pict/Html/Pict.html
COMMENT=	Concurrent language based on Milner's pi calculus
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=		no

USE_TOOLS+=		gmake
INSTALLATION_DIRS+=	bin lib/pict share/doc/pict

MAKE_ENV+=		X11INCLUDE=${X11BASE}/include \
			X11LIB=${X11BASE}/lib

TEST_TARGET=	test

.include "../../lang/ocaml/ocaml.mk"

.if !empty(OCAML_USE_OPT_COMPILER:Myes)
MAKE_ENV+=		OCAMLOPT=yes
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/Doc/*.ps ${DESTDIR}${PREFIX}/share/doc/pict/

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
