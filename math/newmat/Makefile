# $NetBSD: Makefile,v 1.1.1.1 2002/10/16 15:40:33 jschauma Exp $
#

DISTNAME=	newmat10
PKGNAME=	${DISTNAME:C/([0-9]+)$/-\1/}
CATEGORIES=	math devel
MASTER_SITES=	http://www.robertnz.net/ftp/

MAINTAINER=	jschauma@netbsd.org
HOMEPAGE=	http://www.robertnz.net/ol_doc.htm
COMMENT=	Newmat C++ Matrix Library

WRKSRC=		${WRKDIR}
MAKEFILE=	nm_cc.mak
ALL_TARGET=	garch

HEADERS=	boolean.h controlw.h include.h myexcept.h newmat.h 	\
		newmatap.h newmatio.h newmatnl.h newmatrc.h precisio.h

DOCDIR=		${PREFIX}/share/doc/html/newmat

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/newmat
.for header in ${HEADERS}
	${INSTALL_DATA} ${WRKSRC}/${header} ${PREFIX}/include/newmat
.endfor
	${INSTALL_DATA} ${WRKSRC}/libnewmat.a ${PREFIX}/lib
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/nm10.htm ${DOCDIR}/index.html

.include "../../mk/bsd.pkg.mk"
