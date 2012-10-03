# $NetBSD: Makefile,v 1.20 2012/10/03 11:24:39 asau Exp $

DISTNAME=	dl-ezkit-0.8.1-bsd
PKGNAME=	dl-ezkit-0.8.1
CATEGORIES=	comms
MASTER_SITES=	http://www.ww.tu-freiberg.de/~pberg/download/Unix-sources/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ww.tu-freiberg.de/~pberg/download/
COMMENT=	Coff file downloader for the EZ-KIT Lite using the RS232

MAKE_FILE=	Makefile.bsd

WRKSRC=		${WRKDIR}/dl-ezkit

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dl ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
