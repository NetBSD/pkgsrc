# $NetBSD: Makefile,v 1.1.1.1 2001/03/23 20:07:33 fredb Exp $
#

DISTNAME=		pinfo-0.6.0
CATEGORIES=		misc
MASTER_SITES=		http://zeus.polsl.gliwice.pl/~pborys/stable-version/

MAINTAINER=		fredb@netbsd.org
HOMEPAGE=		http://zeus.polsl.gliwice.pl/~pborys/
COMMENT=		Przemek's Info Viewer

BUILD_DEPENDS+=		msgfmt:../../devel/gettext
DEPENDS+=		ncurses>=5.0:../../devel/ncurses

GNU_CONFIGURE=		yes
USE_LIBINTL=		yes

CONFIGURE_ARGS+=	--with-ncurses=${LOCALBASE}

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/pinforc ${PREFIX}/share/examples/

.include "../../mk/bsd.pkg.mk"
