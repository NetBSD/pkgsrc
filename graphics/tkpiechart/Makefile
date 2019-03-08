# $NetBSD: Makefile,v 1.22 2019/03/08 08:42:09 wiz Exp $

DISTNAME=	tkpiechart-5.4
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://jfontain.free.fr/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jfontain.free.fr/
COMMENT=	Tcl/Tk pie-chart utility; in Tcl, not as an extension

DEPENDS+=	tk>=8.3.2:../../x11/tk
DEPENDS+=	tcllib-[0-9]*:../../devel/tcllib

NO_CONFIGURE=	yes
NO_BUILD=	yes

SUBST_CLASSES+=		patch
SUBST_MESSAGE.patch=	Remove version numbers for required packages.
# not a good phase due to interaction with patches, but neither
# configure nor build phases exist
SUBST_STAGE.patch=	post-patch
SUBST_FILES.patch+=	INSTALL
SUBST_FILES.patch+=	demo
SUBST_FILES.patch+=	demo.tcl
SUBST_FILES.patch+=	instapkg.tcl
SUBST_FILES.patch+=	piechart.htm
SUBST_SED.patch=	-e '/require/s/stooop 3.7/stooop/g'
SUBST_SED.patch+=	-e '/require/s/switched 1.4/switched/g'

INSTALLATION_DIRS+=	lib/tcl/tkpiechart

post-patch:
	${CHMOD} a+x ${WRKSRC}/instapkg.tcl

do-install:
	cd ${WRKSRC}; ./instapkg.tcl ${DESTDIR}${PREFIX}/lib/tcl/tkpiechart

.include "../../mk/bsd.pkg.mk"
