# $NetBSD: Makefile,v 1.1.1.1 2001/09/14 13:23:41 hubertf Exp $

DISTNAME=	cvsup-bin-16.1d
PKGNAME=	cvsup-gui-16.1.d
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.pasta.cs.uit.no/pub/cvsupd/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
COMMENT=	cvsup gui client

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes
NO_BUILD=	yes
ONLY_FOR_PLATFORM=	NetBSD-1.5*-i386

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/cvsup ${PREFIX}/bin/cvsup-gui

.include "../../mk/bsd.pkg.mk"
