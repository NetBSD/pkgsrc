# $NetBSD: Makefile,v 1.18 2003/09/20 14:16:06 salo Exp $
#

DISTNAME=	nmap-3.45
PKGNAME=	nmapfe-0.9.5
PKGREVISION=	9
CATEGORIES=	net security
MASTER_SITES=	http://www.insecure.org/nmap/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=     salo@NetBSD.org
HOMEPAGE=	http://www.insecure.org/nmap/
COMMENT=	Graphical front end to the nmap port scanner

DEPENDS+=	nmap-[23].*:../../net/nmap

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

PATCHDIR=	${.CURDIR}/../../net/nmap/patches
DISTINFO_FILE=	${.CURDIR}/../../net/nmap/distinfo

CONFIGURE_DIRS=	${WRKSRC}/nbase ${WRKSRC}/nmapfe
BUILD_DIRS=	${WRKSRC}/nbase ${WRKSRC}/nmapfe

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nmapfe/nmapfe ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/nmapfe.1 ${PREFIX}/man/man1

.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
