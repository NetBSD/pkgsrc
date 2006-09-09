# $NetBSD: Makefile,v 1.4 2006/09/09 02:41:55 obache Exp $
#

DISTNAME=		azara-2.7-src
PKGNAME=		azara-2.7
PKGREVISION=		2
CATEGORIES=		biology
MASTER_SITES=		ftp://www.bio.cam.ac.uk/pub/azara/

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://www.bio.cam.ac.uk/azara/
COMMENT=		Programs to process and view NMR data

WRKSRC=			${WRKDIR}/azara-2.7

MAKE_FILE=		makefile

do-install:
.for PROG in azara \
		bin2asc \
		combine connect contours \
		deflate \
		extract \
		float2int \
		int2float \
		look_at look_byte look_for \
		mat2par \
		par2mat peak_find peak_fit plot1 plot2 process project \
		reflate \
		slides swap \
		unblock viewer
		${CP} ${WRKSRC}/bin/${PROG} ${PREFIX}/bin
.endfor

.include "../../graphics/glut/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
