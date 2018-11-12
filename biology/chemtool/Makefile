# $NetBSD: Makefile,v 1.58 2018/11/12 03:51:45 ryoon Exp $

DISTNAME=	chemtool-1.6.14
PKGREVISION=	8
CATEGORIES=	biology
MASTER_SITES=	http://ruby.chemie.uni-freiburg.de/~martin/chemtool/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ruby.chemie.uni-freiburg.de/~martin/chemtool/
COMMENT=	Program for drawing organic molecules

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-gnomedir

INSTALLATION_DIRS=	share/doc/chemtool share/examples/chemtool

post-install:
	${INSTALL_DATA} ${WRKSRC}/examples/* ${DESTDIR}${PREFIX}/share/examples/chemtool
	cd ${WRKSRC} && ${INSTALL_DATA} README TODO 			\
		${DESTDIR}${PREFIX}/share/doc/chemtool/

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
