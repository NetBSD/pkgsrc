# $NetBSD: Makefile,v 1.9 2002/02/18 15:14:34 seb Exp $
#

DISTNAME=		pinfo-0.6.1
CATEGORIES=		misc
MASTER_SITES=		http://zeus.polsl.gliwice.pl/~pborys/stable-version/

MAINTAINER=		fredb@netbsd.org
HOMEPAGE=		http://zeus.polsl.gliwice.pl/~pborys/
COMMENT=		Przemek's Info Viewer

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_LIBINTL=		yes

CPPFLAGS=		-DDFLT_INFOPATH='\"/usr/share/info:${X11BASE}/info:${LOCALBASE}/info:/usr/local/info\"'

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/pinforc ${PREFIX}/share/examples/

.include "../../mk/bsd.prefs.mk"

.if defined(PINFO_USE_NATIVE_CURSES) && ${PINFO_USE_NATIVE_CURSES} == "YES"
CONFIGURE_ARGS+=	--with-vcurses
.else
DEPENDS+=		ncurses>=5.0:../../devel/ncurses
CONFIGURE_ARGS+=	--with-ncurses=${LOCALBASE}
.endif

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
