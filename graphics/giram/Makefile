# $NetBSD: Makefile,v 1.2 1999/06/21 09:17:20 sakamoto Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1999/06/19 17:38:24 cpiazza Exp $

DISTNAME=	Giram-0.0.18
PKGNAME=	giram-0.0.18
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.minet.net/pub/giram/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.minet.net/giram/

DEPENDS+=	gtk+-1.2.2:../../x11/gtk
DEPENDS+=	Mesa-3.0:../../graphics/Mesa
RUN_DEPENDS=	povray:../../graphics/povray

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG="${X11BASE}/bin/gtk-config" \
		CFLAGS="-I${LOCALBASE}/include ${CFLAGS}"

post-install:
	@${MKDIR} ${PREFIX}/Giram/SampleScenes
	${INSTALL_DATA} ${WRKSRC}/SampleScenes/* ${PREFIX}/Giram/SampleScenes/

.include "../../mk/bsd.pkg.mk"
