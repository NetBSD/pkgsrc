# $NetBSD: Makefile,v 1.28 2012/12/12 10:44:10 wiz Exp $

DISTNAME=	zoom-1.0.3
PKGREVISION=	9
CATEGORIES=	games
MASTER_SITES=	http://www.logicalshift.co.uk/unix/zoom/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.logicalshift.demon.co.uk/unix/zoom/
COMMENT=		Plays Infocom-compatible games, with graphics support

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake perl
GNU_CONFIGURE=		yes

.if ${MACHINE_ARCH} == "alpha"
GCC_REQD+=		3.0
.endif
UNLIMIT_RESOURCES+=	datasize

DOCDIR=			${PREFIX}/share/doc/html/zoom

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	for f in colours.png configXwin.html configmac.html fonts.png \
		game.png generalset.png idx index.html intro.html \
		resources.png troubleshooting.html ui.png zicon.gif \
		zoom-icon.png zoom.html ztitle.html; \
	do \
		${INSTALL_DATA} ${WRKSRC}/manual/$$f ${DESTDIR}${DOCDIR}; \
	done

BUILDLINK_DEPMETHOD.libXt=	build

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/t1lib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
