# $NetBSD: Makefile,v 1.8 2003/08/10 03:15:28 grant Exp $

DISTNAME=	cvsup-gui-static-16.1.f
PKGNAME=	${DISTNAME:C/-static//}
WRKSRC=		${WRKDIR}
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.pasta.cs.uit.no/pub/cvsupd/${MACHINE_ARCH}-${OS_VERSION:C/(...).*/\1/}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://people.freebsd.org/~jdp/
COMMENT=	cvsup GUI client

DEPENDS+=	cvsup-[0-9]*:../../devel/cvsup

NO_CONFIGURE=	yes
NO_BUILD=	yes
ONLY_FOR_PLATFORM=	NetBSD-1.[5-9]*-i386
DIST_SUBDIR=	cvsup-${MACHINE_ARCH}-${OS_VERSION:C/(...).*/\1/}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/cvsup ${PREFIX}/bin/cvsup-gui

.include "../../mk/bsd.pkg.mk"
