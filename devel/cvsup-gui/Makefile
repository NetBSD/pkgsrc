# $NetBSD: Makefile,v 1.2 2001/09/22 19:53:22 hubertf Exp $

# XXX there's some newer version at 
# http://people.freebsd.org/~jdp/s1g/

DISTNAME=	cvsup-bin-16.1d
PKGNAME=	cvsup-gui-16.1.d
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.pasta.cs.uit.no/pub/cvsupd/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://people.freebsd.org/~jdp/
COMMENT=	cvsup gui client

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes
NO_BUILD=	yes
ONLY_FOR_PLATFORM=	NetBSD-1.5*-i386

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/cvsup ${PREFIX}/bin/cvsup-gui

.include "../../mk/bsd.pkg.mk"
