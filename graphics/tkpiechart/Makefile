# $NetBSD: Makefile,v 1.14 2006/02/05 23:09:39 joerg Exp $

DISTNAME=	tkpiechart-5.4
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://jfontain.free.fr/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://jfontain.free.fr/
COMMENT=	Tcl/Tk pie-chart utility; in Tcl, not as an extension

DEPENDS+=	tk>=8.3.2:../../x11/tk
DEPENDS+=	stooop>=3.7:../../devel/stooop

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_CONFIGURE=	yes
NO_BUILD=	yes

SUBST_CLASSES+=		patch
SUBST_MESSAGE.patch=	"Remove version numbers for required packages."
SUBST_STAGE.patch=	post-patch
SUBST_FILES.patch=	demo demo.tcl instapkg.tcl piechart.htm
SUBST_SED.patch=	-e '/require/s/stooop 3.7/stooop/g' \
			-e '/require/s/switched 1.4/switched/g'

post-patch:
	${CHMOD} a+x ${WRKSRC}/instapkg.tcl

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/tcl/tkpiechart
	cd ${WRKSRC}; ./instapkg.tcl ${PREFIX}/lib/tcl/tkpiechart

.include "../../mk/bsd.pkg.mk"
