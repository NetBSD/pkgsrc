# $NetBSD: Makefile,v 1.37 2008/01/04 20:34:13 markd Exp $
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

PKG_DESTDIR_SUPPORT=	destdir

WRKSRC=		${WRKDIR}/boolean
# avoid lowercasing files
EXTRACT_OPTS_ZIP=	-aqo

GCC_REQD+=	3.0
USE_TOOLS+=	gmake pkg-config tar
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
		&& ${PAX} -rw default gdsuser ${DESTDIR}${PREFIX}/share/boolean
	cd ${WRKSRC}/docs						\
		&& ${PAX} -rw html ${DESTDIR}${PREFIX}/share/boolean
	${CHOWN} -R ${BINOWN}:${BINGRP} ${DESTDIR}${PREFIX}/share/boolean
	${INSTALL_SCRIPT} ${WRKSRC}/bin/boolean  ${DESTDIR}${PREFIX}/bin/boolean
	${INSTALL_PROGRAM} ${WRKSRC}/apps/edit/edit  ${DESTDIR}${PREFIX}/bin/edit

.include "../../x11/wxGTK/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
