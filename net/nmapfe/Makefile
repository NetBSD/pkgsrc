# $NetBSD: Makefile,v 1.12 2003/05/02 11:56:09 wiz Exp $
#

DISTNAME=	nmap-3.27
PKGNAME=	nmapfe-0.9.5
PKGREVISION=	5
CATEGORIES=	net security
MASTER_SITES=	http://www.insecure.org/nmap/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=     salo@netbsd.org
HOMEPAGE=	http://www.insecure.org/nmap/
COMMENT=	graphical front end to the nmap port scanner

DEPENDS+=	nmap-[23].*:../../net/nmap

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

PATCHDIR=	${.CURDIR}/../../net/nmap/patches
DISTINFO_FILE=	${.CURDIR}/../../net/nmap/distinfo

BUILD_DIRS=	${WRKSRC}/nbase ${WRKSRC}/nmapfe

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nmapfe/nmapfe ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/nmapfe.1 ${PREFIX}/man/man1

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
