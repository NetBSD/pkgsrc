# $NetBSD: Makefile,v 1.20 2004/01/22 07:20:07 grant Exp $

DISTNAME=		chemtool-1.6
CATEGORIES=		biology
MASTER_SITES=		http://ruby.chemie.uni-freiburg.de/~martin/chemtool/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://ruby.chemie.uni-freiburg.de/~martin/chemtool/
COMMENT=		Program for drawing organic molecules

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/chemtool
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/chemtool
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/chemtool
	cd ${WRKSRC} && ${INSTALL_DATA} README TODO 			\
		${PREFIX}/share/doc/chemtool/

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
