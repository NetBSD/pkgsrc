# $NetBSD: Makefile,v 1.18 2002/03/13 17:37:08 fredb Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1999/06/19 17:38:24 cpiazza Exp $

DISTNAME=	Giram-0.1.2
PKGNAME=	giram-0.1.2
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.minet.net/pub/giram/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.minet.net/giram/
COMMENT=	Giram is Really A Modeller

DEPENDS+=	esound-[0-9]*:../../audio/esound
DEPENDS+=	gnome-libs>=1.4.1.2nb1:../../x11/gnome-libs
DEPENDS+=	povray-[0-9]*:../../graphics/povray

USE_X11=	yes
USE_MESA=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

EVAL_PREFIX+=	GTKDIR=gtk+
CONFIGURE_ENV=	GTK_CONFIG="${GTKDIR}/bin/gtk-config" \
		PKGLOCALEDIR="${PKGLOCALEDIR}" \
		CFLAGS="-I${LOCALBASE}/include ${CFLAGS}"

post-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/share/examples/Giram
	${INSTALL_DATA} ${WRKSRC}/SampleScenes/* ${PREFIX}/share/examples/Giram/

.include "../../mk/bsd.pkg.mk"
