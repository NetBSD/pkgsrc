# $NetBSD: Makefile,v 1.3 2001/03/26 00:28:11 fredb Exp $
#

DISTNAME=		pinfo-0.6.0
PKGNAME=		pinfo-0.6.0nb1
CATEGORIES=		misc
MASTER_SITES=		http://zeus.polsl.gliwice.pl/~pborys/stable-version/

MAINTAINER=		fredb@netbsd.org
HOMEPAGE=		http://zeus.polsl.gliwice.pl/~pborys/
COMMENT=		Przemek's Info Viewer

BUILD_DEPENDS+=		msgfmt:../../devel/gettext
DEPENDS+=		ncurses>=5.0:../../devel/ncurses

GNU_CONFIGURE=		yes
USE_LIBINTL=		yes

CPPFLAGS+=		-DDFLT_INFOPATH='\"/usr/share/info:${X11BASE}/info:${LOCALBASE}/info:/usr/local/info\"'
CONFIGURE_ARGS+=	--with-ncurses=${LOCALBASE}
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/pinforc ${PREFIX}/share/examples/

.include "../../mk/bsd.pkg.mk"
