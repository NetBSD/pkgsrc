# $NetBSD: Makefile,v 1.33 2001/11/29 19:46:11 jlam Exp $

DISTNAME=		gnome-games-1.4.0.3
CATEGORIES=		games gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnome-games/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME games collection

BUILD_DEPENDS+=		automake>=1.4:../../devel/automake
# Required for ports which don't build "libgtop".
DEPENDS+=		guile-[0-9]*:../../lang/guile
BUILD_USES_MSGFMT=	YES

CONFLICTS=		xbill-[0-9]*

USE_GMAKE=		YES
USE_X11BASE=		YES
USE_CURSES=		YES
USE_LIBTOOL=		YES
USE_LIBINTL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
BUILD_USES_GETTEXT_M4=	YES

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		LOCALEDIR=${LOCALEDIR}
CONFIGURE_ARGS+=	--localstatedir=/var
CFLAGS+=		-I${LOCALBASE}/include

INSTALL_FILE=		${WRKDIR}/INSTALL

AUTOGEN_ENV=		NOCONFIGURE=1
AUTOGEN_ENV+=		srcdir=${WRKSRC}

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${AUTOGEN_ENV} ${SH} macros/autogen.sh

post-build:
	${SED} -e 's#@@INSTALL@@#${INSTALL}#' \
	  ${PKGDIR}/INSTALL >${INSTALL_FILE}

.include "../../mk/bsd.prefs.mk"

# The directory in which locale files are found is:
#
#	${PREFIX}/${LOCALEDIR}/locale/<lang>/LC_MESSAGES
#
.if ${OPSYS} == "SunOS"
LOCALEDIR=		lib
.else
LOCALEDIR=		share
.endif

.if ${NEED_NCURSES} == "YES"
CONFIGURE_ARGS+=--with-ncurses=${LOCALBASE}
.endif

.include "../../x11/gnome-core/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
