# $NetBSD: Makefile,v 1.36 2007/03/12 06:46:41 wiz Exp $
#

DISTNAME=	boolean_6_92
PKGNAME=	boolean-6.92
PKGREVISION=	1
CATEGORIES=	cad graphics
MASTER_SITES=	http://www.xs4all.nl/~kholwerd/download/boolzip/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.xs4all.nl/~kholwerd/bool.html
COMMENT=	GDSII viewer/editor + (boolean) operations on sets of 2d polygons

WRKSRC=		${WRKDIR}/boolean
# avoid lowercasing files
EXTRACT_OPTS_ZIP=	-aqo

GCC_REQD+=	3.0
USE_TOOLS+=	gmake pkg-config tar
USE_LANGUAGES=	c c++

SUBST_CLASSES+=		prefix
SUBST_FILES.prefix=	bin/boolean
SUBST_SED.prefix=	-e 's;@prefix@;${PREFIX};g'
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Fixing installation prefix.

INSTALLATION_DIRS=	bin

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${LOCALBASE}/bin/cmake \
		-DWXWIDGET_GTK2=YES .

do-install:
	${INSTALL_DATA_DIR}  ${PREFIX}/share/boolean
	cd ${WRKSRC}/apps/edit						\
		&& ${PAX} -rw default gdsuser ${PREFIX}/share/boolean
	cd ${WRKSRC}/docs						\
		&& ${PAX} -rw html ${PREFIX}/share/boolean
	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/share/boolean
	${INSTALL_SCRIPT} ${WRKSRC}/bin/boolean  ${PREFIX}/bin/boolean
	${INSTALL_PROGRAM} ${WRKSRC}/apps/edit/edit  ${PREFIX}/bin/edit

.include "../../devel/cmake/buildlink3.mk"
.include "../../x11/wxGTK/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
