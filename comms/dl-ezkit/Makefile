# $NetBSD: Makefile,v 1.19 2011/02/28 14:52:42 wiz Exp $

DISTNAME=	dl-ezkit-0.8.1-bsd
PKGNAME=	dl-ezkit-0.8.1
CATEGORIES=	comms
MASTER_SITES=	http://www.ww.tu-freiberg.de/~pberg/download/Unix-sources/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ww.tu-freiberg.de/~pberg/download/
COMMENT=	Coff file downloader for the EZ-KIT Lite using the RS232

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_FILE=	Makefile.bsd

WRKSRC=		${WRKDIR}/dl-ezkit

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dl ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
