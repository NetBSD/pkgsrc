# $NetBSD: Makefile,v 1.4 2000/04/16 17:26:31 jlam Exp $

PKGNAME=	${DISTNAME:S/-/-x11-/}nb1
CATEGORIES+=	x11

DEPENDS+=	ghostscript-5.50:../../print/ghostscript5

USE_X11=	# defined

MAKE_ENV+=	USE_X11=
SCRIPTS_ENV+=	USE_X11=yes

post-extract:	common-post-extract

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/obj/gs ${PREFIX}/bin/gs

.include "../../print/ghostscript5/Makefile.common"
