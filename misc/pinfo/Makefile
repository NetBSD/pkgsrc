# $NetBSD: Makefile,v 1.14 2003/08/03 00:46:22 seb Exp $
#

DISTNAME=		pinfo-0.6.1
PKGREVISION=		1
CATEGORIES=		misc
MASTER_SITES=		http://zeus.polsl.gliwice.pl/~pborys/stable-version/

MAINTAINER=		fredb@NetBSD.org
HOMEPAGE=		http://zeus.polsl.gliwice.pl/~pborys/
COMMENT=		Przemek's Info Viewer

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

USE_NEW_TEXINFO=	YES
INFO_FILES=	pinfo.info

CPPFLAGS=		-DDFLT_INFOPATH='\"/usr/share/info:${X11BASE}/info:${LOCALBASE}/info:/usr/local/info\"'

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/pinforc ${PREFIX}/share/examples/

.include "../../mk/bsd.prefs.mk"

.if defined(PINFO_USE_NATIVE_CURSES) && ${PINFO_USE_NATIVE_CURSES} == "YES"
CONFIGURE_ARGS+=	--with-vcurses
.else
.include "../../devel/ncurses/buildlink2.mk"
CONFIGURE_ARGS+=	--with-ncurses=${BUILDLINK_PREFIX.ncurses}
.endif

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
