# $NetBSD: Makefile,v 1.15 2006/01/04 04:29:08 schmonz Exp $

DISTNAME=	nfsshell-1.0
CATEGORIES=	net security
MASTER_SITES=	http://www.asmodeus.com/archive/Xnix/
DISTFILES=	nfsBugFerret.tgz \
		nfsShell.c

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	NFS security verification suite

BROKEN_IN=	pkgsrc-2005Q4

EXTRACT_ONLY=   nfsBugFerret.tgz
WRKSRC=		${WRKDIR}/nfsbug


# Only works on 1.5B or greater on most platforms but will work on any x86
# since struct pmap didn't get exposed through vm.h there.
ONLY_FOR_PLATFORM=	NetBSD-1.5[B-Z]-* NetBSD-1.5Z[A-Z]-*
ONLY_FOR_PLATFORM+=	NetBSD-1.6*-* NetBSD-[2-9]*-*
ONLY_FOR_PLATFORM+=	NetBSD-*-i386

INSTALLATION_DIRS=	bin

post-extract:
	${CP} ${DISTDIR}/nfsShell.c ${WRKSRC}/nfsshell.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nfsbug ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nfsshell ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
