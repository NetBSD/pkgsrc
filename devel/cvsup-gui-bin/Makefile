# $NetBSD: Makefile,v 1.3 2004/01/16 03:47:06 xtraeme Exp $

DISTNAME=	cvsup-gui-static-16.1.h
PKGNAME=	${DISTNAME:C/-static//}
WRKSRC=		${WRKDIR}
CATEGORIES=	devel
MASTER_SITES=	http://motoyuki.bsdclub.org/data/NetBSD/CVSup/i386/
EXTRACT_SUFX=	.tgz

MAINTAINER=	motoyuki@bsdclub.org
HOMEPAGE=	http://www.polstra.com/projects/freeware/CVSup/
COMMENT=	cvsup GUI client

DEPENDS+=	cvsup-bin-[0-9]*:../../devel/cvsup-bin

NO_CONFIGURE=	yes
NO_BUILD=	yes
DIST_SUBDIR=	cvsup-${MACHINE_ARCH}-${OS_VERSION:C/(...).*/\1/}

ONLY_FOR_PLATFORM=      NetBSD-1.[5-9]*-i386

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/cvsup ${PREFIX}/bin/cvsup-gui

.include "../../mk/bsd.pkg.mk"
