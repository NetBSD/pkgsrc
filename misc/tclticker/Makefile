# $NetBSD: Makefile,v 1.2 2000/01/10 01:39:02 wiz Exp $
#

DISTNAME=	tclticker-1.1
CATEGORIES=	misc tk80
MASTER_SITES=	http://www.neosoft.com/tcl/ftparchive/sorted/apps/tclticker/1.1/

MAINTAINER=	packages@netbsd.org
#HOMEPAGE=	

DEPENDS+=	tk-8.0.5:../../x11/tk80

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
	cd ${WRKSRC}/lib ; ${GTAR} cf - . | (cd ${PREFIX}/share/tclticker ; ${GTAR} xvf - )

.include "../../mk/bsd.pkg.mk"
