# $NetBSD: Makefile,v 1.4 2004/04/23 18:07:06 wiz Exp $

DISTNAME=	cvsup-static-16.1.h
PKGNAME=	${DISTNAME:C/static/bin/}
CATEGORIES=	devel
MASTER_SITES=	http://motoyuki.bsdclub.org/data/NetBSD/CVSup/i386/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://people.freebsd.org/~jdp/
COMMENT=	cvsup daemon and client

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes
NO_BUILD=	yes
ONLY_FOR_PLATFORM=	NetBSD-1.[5-9]*-i386 NetBSD-[2-9]*-i386
# remove on next update -- see PR 25255 for details
DIST_SUBDIR=	cvsup-i386-1.6

CONFLICTS=	cvsup-[0-9]* cvsup-gui-[0-9]*

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
	${INSTALL_DATA} ${FILESDIR}/supfile* \
		${PREFIX}/share/examples/cvsup

.include "../../mk/bsd.pkg.mk"
