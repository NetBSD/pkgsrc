# $NetBSD: Makefile,v 1.20 2002/10/20 13:37:17 wiz Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1999/06/19 17:38:24 cpiazza Exp $

DISTNAME=	Giram-0.1.2
PKGNAME=	giram-0.1.2
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.minet.net/pub/giram/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.minet.net/giram/
COMMENT=	Giram is Really A Modeller

DEPENDS+=	povray-[0-9]*:../../graphics/povray

USE_BUILDLINK2=	yes
USE_X11=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	PKGLOCALEDIR="${PKGLOCALEDIR}"

post-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/share/examples/Giram
	${INSTALL_DATA} ${WRKSRC}/SampleScenes/* ${PREFIX}/share/examples/Giram/

.include "../../graphics/Mesa/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
