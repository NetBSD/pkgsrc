# $NetBSD: Makefile,v 1.27 2005/08/26 11:53:32 adam Exp $

DISTNAME=	chemtool-1.6.7
CATEGORIES=	biology
MASTER_SITES=	http://ruby.chemie.uni-freiburg.de/~martin/chemtool/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://ruby.chemie.uni-freiburg.de/~martin/chemtool/
COMMENT=	Program for drawing organic molecules

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-gnomedir

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/chemtool
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/chemtool
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/chemtool
	cd ${WRKSRC} && ${INSTALL_DATA} README TODO 			\
		${PREFIX}/share/doc/chemtool/

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
