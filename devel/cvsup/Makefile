# $NetBSD: Makefile,v 1.7 2002/09/05 23:52:41 hubertf Exp $

DISTNAME=	cvsup-static-16.1.f
PKGNAME=	${DISTNAME:C/-static//}
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.pasta.cs.uit.no/pub/cvsupd/${MACHINE_ARCH}-${OS_VERSION:C/(...).*/\1/}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://people.freebsd.org/~jdp/
COMMENT=	cvsup daemon and client

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes
NO_BUILD=	yes
ONLY_FOR_PLATFORM=	NetBSD-1.[5-9]*-i386
DIST_SUBDIR=	cvsup-${MACHINE_ARCH}-${OS_VERSION:C/(...).*/\1/}

do-install:
	for i in cvpasswd cvsup ; do \
		${INSTALL_PROGRAM} ${WRKSRC}/bin/$$i ${PREFIX}/bin; \
	done
	for i in cvsupd; do \
		${INSTALL_PROGRAM} ${WRKSRC}/sbin/$$i ${PREFIX}/sbin; \
	done
	for i in cvpasswd.1 cvsup.1; do \
		${INSTALL_MAN} ${WRKSRC}/man/man1/$$i ${PREFIX}/man/man1; \
	done
	for i in cvsupd.8; do \
		${INSTALL_MAN} ${WRKSRC}/man/man8/$$i ${PREFIX}/man/man8; \
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cvsup
	${INSTALL_DATA} ${WRKSRC}/share/doc/cvsup/License \
		${PREFIX}/share/doc/cvsup
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/cvsup
	${INSTALL_DATA} ${FILESDIR}/supfile-cvsup.no.netbsd.org \
		${PREFIX}/share/examples/cvsup

.include "../../mk/bsd.pkg.mk"
