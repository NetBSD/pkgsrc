# $NetBSD: Makefile,v 1.61 2019/07/21 22:24:29 wiz Exp $

DISTNAME=	chemtool-1.6.14
PKGREVISION=	11
CATEGORIES=	biology
MASTER_SITES=	http://ruby.chemie.uni-freiburg.de/~martin/chemtool/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ruby.chemie.uni-freiburg.de/~martin/chemtool/
COMMENT=	Program for drawing organic molecules
LICENSE=	gnu-gpl-v2

DEPENDS+=	fig2dev-[0-9]*:../../print/fig2dev

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-gnomedir

LIBS+=			${LDFLAGS}
INSTALLATION_DIRS=	share/doc/chemtool share/examples/chemtool

post-install:
	${INSTALL_DATA} ${WRKSRC}/examples/* ${DESTDIR}${PREFIX}/share/examples/chemtool
	cd ${WRKSRC} && ${INSTALL_DATA} README TODO 			\
		${DESTDIR}${PREFIX}/share/doc/chemtool/

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
