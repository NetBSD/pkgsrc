# $NetBSD: Makefile,v 1.4 2001/11/14 14:47:57 agc Exp $
#

DISTNAME=	tclticker-1.1
CATEGORIES=	finance tk80
MASTER_SITES=	http://www.neosoft.com/tcl/ftparchive/sorted/apps/tclticker/1.1/

MAINTAINER=	packages@netbsd.org
COMMENT=	Stock-quote ticker tape application

DEPENDS+=	tk>=8.3.2:../../x11/tk

NO_BUILD=	yes

post-patch:
	cd ${WRKSRC}; 							\
	for f in tclticker mailquote; do				\
		${MV} $$f $$f-prefix;					\
		${SED} -e 's|@PREFIX@|${PREFIX}|g' $$f-prefix > $$f;	\
	done

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tclticker ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mailquote ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/tclticker
	cd ${WRKSRC}/lib && ${PAX} -rw . ${PREFIX}/share/tclticker

.include "../../mk/bsd.pkg.mk"
