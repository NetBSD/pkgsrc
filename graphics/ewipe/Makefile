# $NetBSD: Makefile,v 1.4 2017/08/01 16:47:39 wiz Exp $
#

DISTNAME=	ewipe-1.2.0
CATEGORIES=	graphics japanese
MASTER_SITES=	http://www.jnet-jp.to/~sekisita/ewipe/

MAINTAINER=	reed@reedmedia.net
#HOMEPAGE=	http://www.jnet-jp.to/~sekisita/ewipe/index-e.html
COMMENT=	Presentation editor and viewer based on Tcl/Tk

NO_BUILD=	yes
NO_CONFIGURE=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	wish:run

SUBST_CLASSES+=		wish
SUBST_MESSAGE.wish=	Fixing a hardcoded command and path.
SUBST_STAGE.wish=	pre-install
SUBST_FILES.wish=	ewipe
SUBST_SED.wish=		-e 's,exec wish,exec ${WISH},'
SUBST_SED.wish+=	-e 's,PATH \.,PATH ${PREFIX}/share/ewipe,'

INSTALLATION_DIRS=	bin share/ewipe share/doc/ewipe share/examples/ewipe

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ewipe ${DESTDIR}${PREFIX}/bin
.for i in definefont.tcl edittable.tcl setpointer.tcl viewer.tcl tclIndex
	${INSTALL_DATA} ${WRKSRC}/${i} ${DESTDIR}${PREFIX}/share/ewipe/
.endfor
.for i in README dot.ewipe Changes.jp README.jp
	${INSTALL_DATA} ${WRKSRC}/${i} ${DESTDIR}${PREFIX}/share/doc/ewipe/
.endfor
.for i in a1.gif a2.gif a3.gif a4.gif blue1.gif sample.ewp test.ewp tutorial-e.ewp tutorial.ewp
	${INSTALL_DATA} ${WRKSRC}/sample/${i} \
		${DESTDIR}${PREFIX}/share/examples/ewipe/
.endfor

.include "../../mk/bsd.pkg.mk"
