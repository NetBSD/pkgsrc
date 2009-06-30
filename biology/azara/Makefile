# $NetBSD: Makefile,v 1.8 2009/06/30 00:07:10 joerg Exp $
#

DISTNAME=		azara-2.7-src
PKGNAME=		azara-2.7
PKGREVISION=		2
CATEGORIES=		biology
MASTER_SITES=		http://www.ccpn.ac.uk/download/azara/

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://www.ccpn.ac.uk/azara/
COMMENT=		Programs to process and view NMR data

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

WRKSRC=			${WRKDIR}/azara-2.7
MAKE_FILE=		makefile

INSTALLATION_DIRS=	bin

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
		${CP} ${WRKSRC}/bin/${PROG} ${DESTDIR}${PREFIX}/bin
.endfor

.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
