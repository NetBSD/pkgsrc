# $NetBSD: Makefile,v 1.41 2008/09/22 20:21:03 joerg Exp $
#

DISTNAME=	boolean_6_92
PKGNAME=	boolean-6.92
PKGREVISION=	2
CATEGORIES=	cad graphics
MASTER_SITES=	http://boolean.klaasholwerda.nl/download/boolzip/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://boolean.klaasholwerda.nl/bool.html
COMMENT=	GDSII viewer/editor + (boolean) operations on sets of 2d polygons

PKG_DESTDIR_SUPPORT=	destdir

WRKSRC=		${WRKDIR}/boolean
# avoid lowercasing files
EXTRACT_OPTS_ZIP=	-aqo

GCC_REQD+=	3.0
USE_TOOLS+=	gmake pax pkg-config tar
USE_LANGUAGES=	c c++
USE_CMAKE=	yes

SUBST_CLASSES+=		prefix
SUBST_FILES.prefix=	bin/boolean
SUBST_SED.prefix=	-e 's;@prefix@;${PREFIX};g'
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Fixing installation prefix.

INSTALLATION_DIRS=	bin

CMAKE_ARGS+=		-DWXWIDGET_GTK2=YES

do-install:
	${INSTALL_DATA_DIR}  ${DESTDIR}${PREFIX}/share/boolean
	cd ${WRKSRC}/apps/edit						\
		&& pax -rw default gdsuser ${DESTDIR}${PREFIX}/share/boolean
	cd ${WRKSRC}/docs						\
		&& pax -rw html ${DESTDIR}${PREFIX}/share/boolean
	${CHOWN} -R ${BINOWN}:${BINGRP} ${DESTDIR}${PREFIX}/share/boolean
	${INSTALL_SCRIPT} ${WRKSRC}/bin/boolean  ${DESTDIR}${PREFIX}/bin/boolean
	${INSTALL_PROGRAM} ${WRKSRC}/apps/edit/edit  ${DESTDIR}${PREFIX}/bin/edit

.include "../../x11/wxGTK26/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
