# $NetBSD: Makefile,v 1.56 2003/09/28 09:13:57 jlam Exp $

DISTNAME=		gnome-games-1.4.0.4
PKGREVISION=		7
CATEGORIES=		games gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-games/1.4/}\
			${MASTER_SITE_LOCAL}
EXTRACT_SUFX=		.tar.bz2
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}			\
			${DISTNAME:S/s-/s-html-/}${EXTRACT_SUFX}

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME games collection

DEPENDS+=		gnome1-dirs>=1.2:../../misc/gnome1-dirs
BUILD_USES_MSGFMT=	YES
BUILD_USES_GETTEXT_M4=	YES

CONFLICTS=		xbill-[0-9]*

AUTOMAKE_REQD=		1.4
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_GMAKE=		YES
USE_X11BASE=		YES
USE_CONFIG_WRAPPER=	YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR}
CONFIGURE_ARGS+=	--localstatedir=/var

INSTALL_FILE=		${WRKDIR}/INSTALL

post-patch:
	cd ${WRKSRC} &&							\
	${CP} gnect/src/connect4.c gnect/src/connect4.c.broken &&	\
	${SED} -e 's|/usr/share|${PREFIX}/share|'			\
		< gnect/src/connect4.c.broken > gnect/src/connect4.c

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/libtoolize --force --copy
	cd ${WRKSRC} && ${ACLOCAL} -I macros
	cd ${WRKSRC} && ${AUTOHEADER}
	cd ${WRKSRC} && ${AUTOMAKE} --add-missing --gnu
	cd ${WRKSRC} && ${AUTOCONF}

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

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
# Required for ports which don't build "libgtop".
.include "../../lang/guile/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gnome-core/buildlink2.mk"
.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
