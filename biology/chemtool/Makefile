# $NetBSD: Makefile,v 1.8 2001/04/28 23:59:18 jtb Exp $

DISTNAME=	chemtool-1.3
CATEGORIES=	biology
MASTER_SITES=	http://www.uni-ulm.de/~s_tvolk/chemtool/src/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.uni-ulm.de/~s_tvolk/chemtool.html
COMMENT=	Program for drawing organic molecules

DEPENDS+=	gtk+>=1.0.0:../../x11/gtk

MAKE_ENV+=	PKGLOCALEDIR="${PKGLOCALEDIR}"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/chemtool
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/chemtool
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/chemtool
	cd ${WRKSRC} && ${INSTALL_DATA} README TODO 			\
		${PREFIX}/share/doc/chemtool/

.include "../../mk/bsd.pkg.mk"
