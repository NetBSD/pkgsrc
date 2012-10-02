# $NetBSD: Makefile,v 1.41 2012/10/02 17:10:37 tron Exp $

DISTNAME=	chemtool-1.6.13
PKGREVISION=	5
CATEGORIES=	biology
MASTER_SITES=	http://ruby.chemie.uni-freiburg.de/~martin/chemtool/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ruby.chemie.uni-freiburg.de/~martin/chemtool/
COMMENT=	Program for drawing organic molecules

PKG_INSTALLATION_TYPES=	overwrite pkgviews

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
