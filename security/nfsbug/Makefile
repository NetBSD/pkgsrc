# $NetBSD: Makefile,v 1.2 1998/11/12 23:48:35 frueauf Exp $

DISTNAME=	nfsshell-1.0
WRKSRC=		${WRKDIR}/nfsbug
CATEGORIES=	net security
MASTER_SITES=	http://www.asmodeus.com/archive/Xnix/
DISTFILES=	nfsBugFerret.tgz \
		nfsShell.c

MAINTAINER=	packages@netbsd.org

EXTRACT_ONLY=   nfsBugFerret.tgz

post-extract:
	${CP} ${DISTDIR}/nfsShell.c ${WRKSRC}/nfsshell.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nfsbug ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nfsshell ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
