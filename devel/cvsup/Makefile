# $NetBSD: Makefile,v 1.1.1.1 2001/03/13 11:28:19 itojun Exp $

DISTNAME=	cvsup-netbsd-ix86-elf-16.1
PKGNAME=	cvsup-16.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.pasta.cs.uit.no/pub/cvsupd/

MAINTAINER=	packages@netbsd.org
COMMENT=	cvsup daemon and client

WRKSRC=		${WRKDIR}/cvsup-bin-16.1
NO_CONFIGURE=	yes
NO_BUILD=	yes
ONLY_FOR_PLATFORM=	NetBSD-1.5*-i386

do-install:
	for i in cvpasswd cvsup cvsup.nogui; do \
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
