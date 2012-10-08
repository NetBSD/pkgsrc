# $NetBSD: Makefile,v 1.3 2012/10/08 09:20:58 asau Exp $
#

DISTNAME=	cfourcc-0.1.2
CATEGORIES=	multimedia
MASTER_SITES=	http://sarovar.org/frs/download.php/551/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sarovar.org/projects/gfourcc
COMMENT=	Command-line tool for changing AVI FourCC codes

WRKSRC=	${WRKDIR}/cfourcc

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cfourcc \
	    ${DESTDIR}${PREFIX}/bin/cfourcc

.include "../../mk/bsd.pkg.mk"
