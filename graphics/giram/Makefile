# $NetBSD: Makefile,v 1.4 1999/08/28 09:43:10 rh Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1999/06/19 17:38:24 cpiazza Exp $

DISTNAME=	Giram-0.1.1
PKGNAME=	giram-0.1.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.minet.net/pub/giram/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.minet.net/giram/

DEPENDS+=	gtk+-1.2.4:../../x11/gtk
DEPENDS+=	Mesa-3.0:../../graphics/Mesa
RUN_DEPENDS=	povray:../../graphics/povray

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG="${X11BASE}/bin/gtk-config" \
		CFLAGS="-I${LOCALBASE}/include ${CFLAGS}"

post-install:
	@${MKDIR} ${PREFIX}/share/examples/Giram
	${INSTALL_DATA} ${WRKSRC}/SampleScenes/* ${PREFIX}/share/examples/Giram/

.include "../../mk/bsd.pkg.mk"
