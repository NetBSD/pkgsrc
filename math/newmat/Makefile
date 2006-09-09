# $NetBSD: Makefile,v 1.10 2006/09/09 02:43:10 obache Exp $
#

DISTNAME=	newmat10 # actually newmat10B, but no such distfile
PKGNAME=	${DISTNAME:C/([0-9]+)$/-\1/}
PKGREVISION=	1
CATEGORIES=	math devel
MASTER_SITES=	http://www.robertnz.net/ftp/

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://www.robertnz.net/ol_doc.htm
COMMENT=	Newmat C++ Matrix Library

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	newmat10B
MAKE_FILE=	nm_cc.mak
BUILD_TARGET=	garch
USE_LANGUAGES=	c++

HEADERS=	boolean.h controlw.h include.h myexcept.h newmat.h 	\
		newmatap.h newmatio.h newmatnl.h newmatrc.h precisio.h

DOCDIR=		${PREFIX}/share/doc/html/newmat

INSTALLATION_DIRS=	lib

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/newmat
.for header in ${HEADERS}
	${INSTALL_DATA} ${WRKSRC}/${header} ${PREFIX}/include/newmat
.endfor
	${INSTALL_DATA} ${WRKSRC}/libnewmat.a ${PREFIX}/lib
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/nm10.htm ${DOCDIR}/index.html

.include "../../mk/bsd.pkg.mk"
