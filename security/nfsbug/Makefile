DISTNAME=	nfsshell-1.0
DISTFILES=	nfsBugFerret.tgz \
		nfsShell.c
MASTER_SITES=	http://www.asmodeus.com/archive/Xnix/
CATEGORIES=	net security

WRKSRC=		${WRKDIR}/nfsbug
EXTRACT_ONLY=   nfsBugFerret.tgz

post-extract:
	${CP} ${DISTDIR}/nfsShell.c ${WRKSRC}/nfsshell.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nfsbug ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nfsshell ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
