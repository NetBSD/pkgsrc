# $NetBSD: Makefile,v 1.8 2003/04/22 10:33:20 salo Exp $
#

DISTNAME=	nmap-3.25
PKGNAME=	nmapfe-0.9.5
PKGREVISION=	2
CATEGORIES=	net security
MASTER_SITES=	http://codebox.net/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=     reinoud@ibbnet.org,hubertf@netbsd.org
HOMEPAGE=	http://www.insecure.org/nmap/index.html
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
