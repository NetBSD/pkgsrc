# $NetBSD: Makefile,v 1.1.1.1 2001/06/05 10:29:38 agc Exp $

DISTNAME=		cfs-1.4.1
CATEGORIES=		security
MASTER_SITES=		http://www.crypto.com/software/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.crypto.com/software/
COMMENT=		encrypting file system, using NFS as its interface

CRYPTO=			yes

INSTALL_TARGET=		install_cfs

do-build:
	cd ${WRKSRC} && ./netbsd_make_with_bad_rpcgen cfs

post-install:
	${BSD_INSTALL_MAN} ${WRKSRC}/cattach.1 ${PREFIX}/man/man1/
	${BSD_INSTALL_MAN} ${WRKSRC}/cdetach.1 ${PREFIX}/man/man1/
	${BSD_INSTALL_MAN} ${WRKSRC}/cfssh.1 ${PREFIX}/man/man1/
	${BSD_INSTALL_MAN} ${WRKSRC}/cmkdir.1 ${PREFIX}/man/man1/
	${BSD_INSTALL_MAN} ${WRKSRC}/cmkkey.1 ${PREFIX}/man/man1/
	${BSD_INSTALL_MAN} ${WRKSRC}/cpasswd.1 ${PREFIX}/man/man1/
	${BSD_INSTALL_MAN} ${WRKSRC}/ccat.8 ${PREFIX}/man/man8/
	${BSD_INSTALL_MAN} ${WRKSRC}/cfsd.8 ${PREFIX}/man/man8/
	${BSD_INSTALL_MAN} ${WRKSRC}/cname.8 ${PREFIX}/man/man8/

.include "../../mk/bsd.pkg.mk"
