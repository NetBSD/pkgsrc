# $NetBSD: Makefile,v 1.9 2004/10/03 00:14:47 tv Exp $
#

DISTNAME=	zoom-1.0.1
PKGNAME=	${DISTNAME}a
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.logicalshift.demon.co.uk/unix/zoom/

PATCH_SITES=		http://www.logicalshift.demon.co.uk/unix/zoom/
PATCHFILES=		zoom-1.0.1-1.0.1a.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://www.logicalshift.demon.co.uk/unix/zoom/
COMMENT=		Plays Infocom-compatible games, with graphics support

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_X11=		yes
USE_GNU_TOOLS+=		make
USE_PERL5=		build

.if ${MACHINE_ARCH} == "alpha"
GCC_REQD+=		3.0
.endif
UNLIMIT_RESOURCES+=	datasize

DOCDIR=			${LOCALBASE}/share/doc/html/zoom
post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	for f in colours.png configXwin.html configmac.html fonts.png \
		game.png generalset.png idx index.html intro.html \
		resources.png troubleshooting.html ui.png zicon.gif \
		zoom-icon.png zoom.html ztitle.html; \
	do \
		${INSTALL_DATA} ${WRKSRC}/manual/$$f ${DOCDIR}; \
	done

.include "../../fonts/Xft2/buildlink3.mk"
.include "../../fonts/t1lib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
