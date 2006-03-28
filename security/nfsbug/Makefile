# $NetBSD: Makefile,v 1.17 2006/03/28 22:07:18 hubertf Exp $

DISTNAME=	nfsshell-1.0
PKGREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	http://www.asmodeus.com/archive/Xnix/
DISTFILES=	nfsBugFerret.tgz \
		nfsShell.c

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	NFS security verification suite

EXTRACT_ONLY=   nfsBugFerret.tgz
WRKSRC=		${WRKDIR}/nfsbug


INSTALLATION_DIRS=	bin

post-extract:
	${CP} ${DISTDIR}/nfsShell.c ${WRKSRC}/nfsshell.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nfsbug ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nfsshell ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
