# $NetBSD: Makefile,v 1.10 2004/01/20 12:10:01 agc Exp $

DISTNAME=	dl-ezkit-0.8.1-bsd
PKGNAME=        dl-ezkit-0.8.1
CATEGORIES=	comms
MASTER_SITES=	http://www.ww.tu-freiberg.de/~pberg/download/Unix-sources/

MAINTAINER=	gmcgarry@NetBSD.org
HOMEPAGE=	http://www.ww.tu-freiberg.de/~pberg/download/
COMMENT=	Coff file downloader for the EZ-KIT Lite using the RS232

MAKEFILE=	Makefile.bsd

WRKSRC=		${WRKDIR}/dl-ezkit
USE_BUILDLINK2=	# defined

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dl ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"

