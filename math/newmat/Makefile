# $NetBSD: Makefile,v 1.13 2009/03/17 21:40:46 darcy Exp $
#

DISTNAME=	newmat10 # actually newmat10B, but no such distfile
PKGNAME=	${DISTNAME:C/([0-9]+)$/-\1/}
PKGREVISION=	1
CATEGORIES=	math devel
MASTER_SITES=	http://www.robertnz.net/ftp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.robertnz.net/ol_doc.htm
COMMENT=	Newmat C++ Matrix Library

PKG_DESTDIR_SUPPORT=	user-destdir

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
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/newmat
.for header in ${HEADERS}
	${INSTALL_DATA} ${WRKSRC}/${header} ${DESTDIR}${PREFIX}/include/newmat
.endfor
	${INSTALL_DATA} ${WRKSRC}/libnewmat.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/nm10.htm ${DESTDIR}${DOCDIR}/index.html

.include "../../mk/bsd.pkg.mk"
