# $NetBSD: Makefile,v 1.23 2012/02/16 19:04:52 hans Exp $

DISTNAME=	dcdflib.c-1.1
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	# ftp://odin.mdacc.tmc.edu/pub/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://odin.mdacc.tmc.edu/anonftp/
COMMENT=	Library of C Routines for Cumulative Distribution Functions

WRKSRC=		${WRKDIR}/dcdflib.c
BUILD_DIRS=	src
DIST_SUBDIR=	${PKGNAME_NOREV}
MAKE_ENV+=	LIBOWN=${LIBOWN:Q} LIBGRP=${LIBGRP:Q}
USE_BSD_MAKEFILE=	yes

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	include lib share/doc/dcdflib.c
MAKE_FLAGS+=		MKPROFILE=yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/dcdflib.h ${DESTDIR}${PREFIX}/include
	cd ${WRKSRC} && ${INSTALL_DATA} README doc/dcdflib.chs		\
		doc/dcdflib.fdoc ${DESTDIR}${PREFIX}/share/doc/dcdflib.c/

.include "../../mk/bsd.pkg.mk"
