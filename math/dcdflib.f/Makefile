# $NetBSD: Makefile,v 1.13 2009/12/12 22:18:00 asau Exp $

DISTNAME=	dcdflib.f-1.1
PKGREVISION=	3
CATEGORIES=	math
MASTER_SITES=	ftp://odin.mdacc.tmc.edu/pub/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://odin.mdacc.tmc.edu/anonftp/
COMMENT=	Library of Fortran Routines for Cumulative Distribution Functions

WRKSRC=		${WRKDIR}/dcdflib.f
BUILD_DIRS=	src
USE_LANGUAGES=	c fortran

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	lib share/doc/dcdflib.f

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DESTDIR}${PREFIX}/share/doc/dcdflib.f
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/dcdflib.f

.include "../../mk/bsd.pkg.mk"
