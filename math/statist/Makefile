# $NetBSD: Makefile,v 1.12 2008/03/04 18:12:59 jlam Exp $
#

DISTNAME=	statist-1.0.1
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://www.usf.uni-osnabrueck.de/~breiter/tools/statist/v${PKGVERSION}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.usf.uni-osnabrueck.de/~breiter/tools/statist/index.en.html
COMMENT=	Small and portable statistics program

DEPENDS+=	gnuplot-[0-9]*:../../graphics/gnuplot

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_LIBTOOL=	YES

INSTALLATION_DIRS=	bin lib

do-install:
	cd ${WRKSRC} &&							\
	${LIBTOOL} --mode=install					\
		${INSTALL_DATA} libstatist.la ${DESTDIR}${PREFIX}/lib &&\
	${LIBTOOL} --mode=install					\
		${INSTALL_PROGRAM} statist ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/statist
	${INSTALL_DATA} ${WRKSRC}/../doc/*.ps				\
		${DESTDIR}${PREFIX}/share/doc/statist

.include "../../mk/bsd.pkg.mk"
