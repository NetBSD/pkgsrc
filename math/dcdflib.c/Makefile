# $NetBSD: Makefile,v 1.16 2006/03/04 21:30:03 jlam Exp $

DISTNAME=	dcdflib.c-1.1
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	ftp://odin.mdacc.tmc.edu/pub/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://odin.mdacc.tmc.edu/anonftp/
COMMENT=	Library of C Routines for Cumulative Distribution Functions

WRKSRC=		${WRKDIR}/dcdflib.c/src
DIST_SUBDIR=	${PKGNAME_NOREV}
MAKE_ENV+=	LIBOWN=${LIBOWN:Q} LIBGRP=${LIBGRP:Q}

INSTALLATION_DIRS=	include share/doc/dcdflib.c

post-install:
	${INSTALL_DATA} ${WRKSRC}/../doc/dcdflib.h ${PREFIX}/include
	cd ${WRKDIR}/dcdflib.c/ && ${INSTALL_DATA} README 		\
	doc/dcdflib.chs doc/dcdflib.fdoc ${PREFIX}/share/doc/dcdflib.c/

.include "../../mk/bsd.pkg.mk"
