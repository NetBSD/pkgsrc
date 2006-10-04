# $NetBSD: Makefile,v 1.43 2006/10/04 21:53:17 wiz Exp $
#

DISTNAME=	nmap-4.11
PKGNAME=	nmapfe-0.9.5
PKGREVISION=	30
CATEGORIES=	net security
MASTER_SITES=	http://insecure.org/nmap/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=     salo@NetBSD.org
HOMEPAGE=	http://insecure.org/nmap/
COMMENT=	Graphical front end to the nmap port scanner

DEPENDS+=	nmap-[234].*:../../net/nmap

GNU_CONFIGURE=	YES
USE_TOOLS+=	pkg-config

PATCHDIR=	${.CURDIR}/../../net/nmap/patches
DISTINFO_FILE=	${.CURDIR}/../../net/nmap/distinfo

CONFIGURE_DIRS=	nbase nmapfe
BUILD_DIRS=	nbase nmapfe

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nmapfe/nmapfe ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/nmapfe.1 ${PREFIX}/man/man1

.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
