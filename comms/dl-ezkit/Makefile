# $NetBSD: Makefile,v 1.4 2001/08/19 03:28:59 jlam Exp $

PKGNAME=        dl-ezkit-0.8.1
DISTNAME=	dl-ezkit-0.8.1-bsd
CATEGORIES=	comms
MASTER_SITES=	http://www.ww.tu-freiberg.de/~pberg/download/Unix-sources/

MAINTAINER=	gmcgarry@netbsd.org
HOMEPAGE=	http://www.ww.tu-freiberg.de/~pberg/download/
COMMENT=	coff file downloader for the EZ-KIT Lite using the RS232

WRKSRC=		${WRKDIR}/dl-ezkit
MAKEFILE=	Makefile.bsd

USE_BUILDLINK_ONLY=	# defined

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dl ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"

