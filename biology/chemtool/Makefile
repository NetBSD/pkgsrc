# $NetBSD: Makefile,v 1.12 2002/05/03 22:03:08 jtb Exp $

DISTNAME=		chemtool-1.4.1
CATEGORIES=		biology
MASTER_SITES=		http://www.uni-ulm.de/~s_tvolk/chemtool/src/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.uni-ulm.de/~s_tvolk/chemtool.html
COMMENT=		Program for drawing organic molecules

USE_BUILDLINK_ONLY=	# defined
MAKE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/chemtool
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/chemtool
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/chemtool
	cd ${WRKSRC} && ${INSTALL_DATA} README TODO 			\
		${PREFIX}/share/doc/chemtool/

.include "../../x11/gtk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
