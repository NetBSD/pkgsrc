# $NetBSD: Makefile,v 1.13 2000/10/15 12:06:41 rh Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1999/06/19 17:38:24 cpiazza Exp $

DISTNAME=	Giram-0.1.2
PKGNAME=	giram-0.1.2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.minet.net/pub/giram/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.minet.net/giram/

DEPENDS+=	esound-*:../../audio/esound
DEPENDS+=	gnome-libs-*:../../x11/gnome-libs
DEPENDS+=	povray-*:../../graphics/povray

USE_X11=	yes
USE_MESA=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

EVAL_PREFIX+=	GTKDIR=gtk+
CONFIGURE_ENV=	GTK_CONFIG="${GTKDIR}/bin/gtk-config" \
		CFLAGS="-I${LOCALBASE}/include ${CFLAGS}"

ALL_TARGET=	install-strip

post-install:
	@${MKDIR} ${PREFIX}/share/examples/Giram
	${INSTALL_DATA} ${WRKSRC}/SampleScenes/* ${PREFIX}/share/examples/Giram/

.include "../../mk/bsd.pkg.mk"
