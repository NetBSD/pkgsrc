# $NetBSD: Makefile,v 1.2 2026/05/08 02:52:30 khorben Exp $

DISTNAME=	picocom-3.1
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_GITHUB:=npat-efault/}
GITHUB_PROJECT=	picocom
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/npat-efault/picocom
COMMENT=	Minimal dumb-terminal emulation program
LICENSE=	gnu-gpl-v2

PC_BINARY=	picocom
PC_SCRIPTS=	pcasc pcxm pcym pczm
PC_MAN=		picocom.1

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PC_BINARY} \
		${DESTDIR}${PREFIX}/bin
.for f in ${PC_SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/${PC_MAN} \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
