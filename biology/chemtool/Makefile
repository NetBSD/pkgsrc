# $NetBSD: Makefile,v 1.68 2023/01/29 21:15:33 ryoon Exp $

DISTNAME=	chemtool-1.6.14
PKGREVISION=	18
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

NOT_PAX_MPROTECT_SAFE+=	bin/chemtool
NOT_PAX_MPROTECT_SAFE+=	bin/chemtoolbg

post-install:
	${INSTALL_DATA} ${WRKSRC}/examples/* ${DESTDIR}${PREFIX}/share/examples/chemtool
	cd ${WRKSRC} && ${INSTALL_DATA} README TODO 			\
		${DESTDIR}${PREFIX}/share/doc/chemtool/

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
