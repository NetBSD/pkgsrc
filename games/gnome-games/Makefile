# $NetBSD: Makefile,v 1.38 2002/07/17 22:21:37 rh Exp $

DISTNAME=		gnome-games-1.4.0.4
PKGREVISION=		1
CATEGORIES=		games gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnome-games/}\
			${MASTER_SITE_LOCAL}
EXTRACT_SUFX=		.tar.bz2
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}			\
			${DISTNAME:S/s-/s-html-/}${EXTRACT_SUFX}

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
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
BUILD_USES_GETTEXT_M4=	YES

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR}
CONFIGURE_ARGS+=	--localstatedir=/var

USE_CONFIG_WRAPPER=	YES

INSTALL_FILE=		${WRKDIR}/INSTALL

AUTOGEN_ENV=		NOCONFIGURE=1
AUTOGEN_ENV+=		srcdir=${WRKSRC}

post-patch:
	cd ${WRKSRC} &&							\
	${CP} gnect/src/connect4.c gnect/src/connect4.c.broken &&	\
	${SED} -e 's|/usr/share|${PREFIX}/share|'			\
		< gnect/src/connect4.c.broken > gnect/src/connect4.c

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${AUTOGEN_ENV} ${SH} macros/autogen.sh

post-build:
	${SED} -e 's#@@INSTALL@@#${INSTALL}#' \
	  ${PKGDIR}/INSTALL >${INSTALL_FILE}

post-install:
.for dir in gnome-stones/C gnome-stones/it
	${ECHO} "index.html Manual" >${PREFIX}/share/gnome/help/${dir}/topic.dat
	${CHMOD} 0644 ${PREFIX}/share/gnome/help/${dir}/topic.dat
.endfor
	${LN} -s aisleriot ${PREFIX}/share/gnome/help/freecell
	${LN} -s . ${PREFIX}/share/gnome/help/gataxx/C/user-guide
	${LN} -s . ${PREFIX}/share/gnome/help/gataxx/es/user-guide
	${LN} -s . ${PREFIX}/share/gnome/help/gataxx/eu/user-guide
	${LN} -s . ${PREFIX}/share/gnome/help/gataxx/it/user-guide
	${LN} -s gnome-mines ${PREFIX}/share/gnome/help/gnomine
	${LN} -s same-gnome ${PREFIX}/share/gnome/help/samegnome

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/ncurses/buildlink.mk"
.include "../../x11/gnome-core/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
