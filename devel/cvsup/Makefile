# $NetBSD: Makefile,v 1.3 2001/09/13 10:58:51 hubertf Exp $

DISTNAME=	cvsup-bin-nogui-16.1d
PKGNAME=	cvsup-16.1.d
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.pasta.cs.uit.no/pub/cvsupd/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
COMMENT=	cvsup daemon and client

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes
NO_BUILD=	yes
ONLY_FOR_PLATFORM=	NetBSD-1.5*-i386
USE_X11=	yes

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

.include "../../mk/bsd.pkg.mk"
