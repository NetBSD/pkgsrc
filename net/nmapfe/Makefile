# $NetBSD: Makefile,v 1.38 2006/02/12 17:24:23 salo Exp $
#

DISTNAME=	nmap-4.01
PKGNAME=	nmapfe-0.9.5
PKGREVISION=	26
CATEGORIES=	net security
MASTER_SITES=	http://www.insecure.org/nmap/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=     salo@NetBSD.org
HOMEPAGE=	http://www.insecure.org/nmap/
COMMENT=	Graphical front end to the nmap port scanner

DEPENDS+=	nmap-[234].*:../../net/nmap

GNU_CONFIGURE=	YES
USE_TOOLS+=	pkg-config

PATCHDIR=	${.CURDIR}/../../net/nmap/patches
DISTINFO_FILE=	${.CURDIR}/../../net/nmap/distinfo

CONFIGURE_DIRS=	${WRKSRC}/nbase ${WRKSRC}/nmapfe
BUILD_DIRS=	${WRKSRC}/nbase ${WRKSRC}/nmapfe

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nmapfe/nmapfe ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/nmapfe.1 ${PREFIX}/man/man1

.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
