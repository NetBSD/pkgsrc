# $NetBSD: Makefile,v 1.1.1.1 2000/03/24 18:25:39 jlam Exp $

PKGNAME=	${DISTNAME:S/-/-x11-/}
CATEGORIES+=	x11

DEPENDS+=	ghostscript-5.50:../../print/ghostscript5

USE_X11=	# defined

MAKE_ENV+=	USE_X11=
SCRIPTS_ENV+=	USE_X11=yes

post-extract:	common-post-extract

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/obj/gs ${PREFIX}/bin/gsx11

post-install:
	strip ${PREFIX}/bin/gsx11
	${LN} -s gs.1 ${PREFIX}/man/man1/gsx11.1

.include "../../print/ghostscript5/Makefile.common"
