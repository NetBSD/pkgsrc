# $NetBSD: Makefile,v 1.17 2003/09/27 17:07:37 grant Exp $
#

DISTNAME=		pinfo-0.6.1
PKGREVISION=		2
CATEGORIES=		misc
MASTER_SITES=		http://zeus.polsl.gliwice.pl/~pborys/stable-version/

MAINTAINER=		fredb@NetBSD.org
HOMEPAGE=		http://zeus.polsl.gliwice.pl/~pborys/
COMMENT=		Przemek's Info Viewer

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_PKGINSTALL=		yes

INFO_FILES=	pinfo.info

CPPFLAGS=		-DDFLT_INFOPATH='\"/usr/share/info:${X11BASE}/info:${LOCALBASE}/info:/usr/local/info\"'

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

CONF_FILES=	${PREFIX}/share/examples/pinfo/pinforc ${PKG_SYSCONFDIR}/pinforc

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/pinfo
	${INSTALL_DATA} ${WRKSRC}/src/pinforc ${PREFIX}/share/examples/pinfo

.include "../../mk/bsd.prefs.mk"

.if defined(PINFO_USE_NATIVE_CURSES) && ${PINFO_USE_NATIVE_CURSES} == "YES"
CONFIGURE_ARGS+=	--with-vcurses
.else
.include "../../mk/curses.buildlink2.mk"
CONFIGURE_ARGS+=	--with-ncurses=${BUILDLINK_PREFIX.ncurses}
.endif

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
