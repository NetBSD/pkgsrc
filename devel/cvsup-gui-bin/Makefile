# $NetBSD: Makefile,v 1.8 2004/04/23 18:07:06 wiz Exp $

DISTNAME=	cvsup-gui-static-16.1.h
PKGNAME=	${DISTNAME:C/static/bin/}
CATEGORIES=	devel
MASTER_SITES=	http://motoyuki.bsdclub.org/data/NetBSD/CVSup/i386/
EXTRACT_SUFX=	.tgz

MAINTAINER=	motoyuki@bsdclub.org
HOMEPAGE=	http://www.polstra.com/projects/freeware/CVSup/
COMMENT=	cvsup GUI client

DEPENDS+=	cvsup-bin-[0-9]*:../../devel/cvsup-bin

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes
NO_BUILD=	yes
# remove on next update -- see PR 25255 for details
DIST_SUBDIR=	cvsup-i386-1.6

ONLY_FOR_PLATFORM=      NetBSD-1.[5-9]*-i386 NetBSD-[2-9]*-i386

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/cvsup ${PREFIX}/bin/cvsup-gui

.include "../../mk/bsd.pkg.mk"
