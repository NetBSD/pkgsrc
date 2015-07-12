# $NetBSD: Makefile,v 1.23 2015/07/12 07:19:13 dholland Exp $

DISTNAME=	nfsshell-1.0
PKGREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	http://www.asmodeus.com/archive/Xnix/
DISTFILES=	nfsBugFerret.tgz \
		nfsShell.c

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	NFS security verification suite

EXTRACT_ONLY=	nfsBugFerret.tgz
WRKSRC=		${WRKDIR}/nfsbug

SUBST_CLASSES+=		getline
SUBST_STAGE.getline=	pre-configure
SUBST_FILES.getline=	nfsshell.c
SUBST_SED.getline+=	-e 's|getline|nfsbug_getline|g'

INSTALLATION_DIRS=	bin

post-extract:
	${CP} ${DISTDIR}/nfsShell.c ${WRKSRC}/nfsshell.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nfsbug ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nfsshell ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
