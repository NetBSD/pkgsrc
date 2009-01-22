# $NetBSD: Makefile,v 1.1.1.1 2009/01/22 12:44:45 jmcneill Exp $
#

DISTNAME=	cfourcc-0.1.2
CATEGORIES=	multimedia
MASTER_SITES=	http://sarovar.org/frs/download.php/551/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sarovar.org/projects/gfourcc
COMMENT=	Command-line tool for changing AVI FourCC codes

PKG_DESTDIR_SUPPORT=	user-destdir
WRKSRC=	${WRKDIR}/cfourcc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cfourcc \
	    ${DESTDIR}${PREFIX}/bin/cfourcc

.include "../../mk/bsd.pkg.mk"
