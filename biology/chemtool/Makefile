# $NetBSD: Makefile,v 1.18 2003/07/17 21:24:41 grant Exp $

DISTNAME=		chemtool-1.4.1
PKGREVISION=		2
CATEGORIES=		biology
MASTER_SITES=		http://www.uni-ulm.de/~s_tvolk/chemtool/src/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.uni-ulm.de/~s_tvolk/chemtool.html
COMMENT=		Program for drawing organic molecules

USE_BUILDLINK2=		# defined
USE_PKGLOCALEDIR=	# defined
USE_X11=		# defined

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/chemtool
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/chemtool
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/chemtool
	cd ${WRKSRC} && ${INSTALL_DATA} README TODO 			\
		${PREFIX}/share/doc/chemtool/

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
