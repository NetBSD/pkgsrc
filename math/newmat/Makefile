# $NetBSD: Makefile,v 1.15 2012/09/11 23:04:25 asau Exp $
#

DISTNAME=	newmat11
PKGNAME=	${DISTNAME:C/([0-9]+)$/-\1/}
CATEGORIES=	math devel
MASTER_SITES=	http://www.robertnz.net/ftp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.robertnz.net/ol_doc.htm
COMMENT=	Newmat C++ Matrix Library

WRKSRC=		${WRKDIR}
MAKE_FILE=	nm_cc.mak
BUILD_TARGET=	garch
USE_LANGUAGES=	c++

HEADERS=	controlw.h include.h myexcept.h newmat.h        \
		newmatap.h newmatio.h newmatnl.h newmatrc.h precisio.h \
		solution.h tmt.h newmatrm.h

INSTALLATION_DIRS=     lib include/newmat share/doc/newmat

do-install:
.for header in ${HEADERS}
	${INSTALL_DATA} ${WRKSRC}/${header} ${DESTDIR}${PREFIX}/include/newmat
.endfor
	${INSTALL_DATA} ${WRKSRC}/libnewmat.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/nm11.htm ${DESTDIR}${PREFIX}/share/doc/newmat/index.html

.include "../../mk/bsd.pkg.mk"
