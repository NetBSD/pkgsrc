# $NetBSD: Makefile,v 1.24 2004/09/01 01:20:51 salo Exp $
#

DISTNAME=	nmap-3.70
PKGNAME=	nmapfe-0.9.5
PKGREVISION=	14
CATEGORIES=	net security
MASTER_SITES=	http://www.insecure.org/nmap/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=     salo@NetBSD.org
HOMEPAGE=	http://www.insecure.org/nmap/
COMMENT=	Graphical front end to the nmap port scanner

DEPENDS+=	nmap-[23].*:../../net/nmap

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES

PATCHDIR=	${.CURDIR}/../../net/nmap/patches
DISTINFO_FILE=	${.CURDIR}/../../net/nmap/distinfo

CONFIGURE_DIRS=	${WRKSRC}/nbase ${WRKSRC}/nmapfe
BUILD_DIRS=	${WRKSRC}/nbase ${WRKSRC}/nmapfe

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nmapfe/nmapfe ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/nmapfe.1 ${PREFIX}/man/man1

.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
