# $NetBSD: Makefile,v 1.7 2003/07/17 22:53:00 grant Exp $

DISTNAME=	nfsshell-1.0
WRKSRC=		${WRKDIR}/nfsbug
CATEGORIES=	net security
MASTER_SITES=	http://www.asmodeus.com/archive/Xnix/
DISTFILES=	nfsBugFerret.tgz \
		nfsShell.c

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	NFS security verification suite

EXTRACT_ONLY=   nfsBugFerret.tgz

# Only works on 1.5B or greater on most platforms but will work on any x86
# since struct pmap didn't get exposed through vm.h there.
ONLY_FOR_PLATFORM=	NetBSD-1.5[B-Z]-* NetBSD-1.5Z[A-Z]-* NetBSD-1.[6-9]*-* \
			NetBSD-*-i386

post-extract:
	${CP} ${DISTDIR}/nfsShell.c ${WRKSRC}/nfsshell.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nfsbug ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nfsshell ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
