# $NetBSD: Makefile,v 1.56 2012/09/15 10:03:47 obache Exp $
#

DISTNAME=	boolean_6_99
PKGNAME=	boolean-6.99
PKGREVISION=	13
CATEGORIES=	cad graphics
MASTER_SITES=	http://boolean.klaasholwerda.nl/download/boolzip/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://boolean.klaasholwerda.nl/bool.html
COMMENT=	GDSII viewer/editor + (boolean) operations on sets of 2d polygons

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/boolean

GCC_REQD+=	3.0
USE_TOOLS+=	gmake pax pkg-config tar
USE_LANGUAGES=	c c++
USE_CMAKE=	yes

INSTALLATION_DIRS=	bin share/boolean

MAKE_ENV+=		wxWidgets_CONFIG_EXECUTABLE=${BUILDLINK_PREFIX.wxGTK28}/bin/wx-config
CMAKE_ARGS+=		-DWXWIDGET_GTK2=YES

SUBST_CLASSES+=		prefix
SUBST_FILES.prefix=	bin/boolean.sh
SUBST_SED.prefix=	-e 's;@prefix@;${PREFIX};g'
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Fixing installation prefix.

do-install:
	cd ${WRKSRC}/apps/edit						\
		&& pax -rw default gdsuser ${DESTDIR}${PREFIX}/share/boolean
	cd ${WRKSRC}/docs						\
		&& pax -rw html ${DESTDIR}${PREFIX}/share/boolean
	${CHOWN} -R ${BINOWN}:${BINGRP} ${DESTDIR}${PREFIX}/share/boolean
	${INSTALL_SCRIPT} ${WRKSRC}/bin/boolean.sh  ${DESTDIR}${PREFIX}/bin/boolean
	${INSTALL_PROGRAM} ${WRKSRC}/bin/edit  ${DESTDIR}${PREFIX}/bin/edit

.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../x11/wxGTK28-contrib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
