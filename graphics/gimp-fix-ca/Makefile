# $NetBSD: Makefile,v 1.1.1.1 2007/06/03 07:48:13 dsainty Exp $
#

DISTNAME=		gimp-fix-ca-2.1.0
CATEGORIES=		graphics
MASTER_SITES=		http://registry.gimp.org/file/fix-ca.c?action=download&id=8944&file=
EXTRACT_SUFX=		.c
FETCH_BEFORE_ARGS+=     -o ${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://kcd.sourceforge.net/fix-ca.php
COMMENT=		GIMP plugin to correct chromatic aberration (CA)

WRKSRC=			${WRKDIR}
NO_CONFIGURE=		yes
INSTALLATION_DIRS=	lib/gimp/2.0/plug-ins

USE_TOOLS+=		pkg-config

pre-build:
	${LN} -sf ${LOCALBASE}/bin/gimptool-2.0 \
		${BUILDLINK_DIR}/bin/gimptool

do-build:
	cd "${WRKDIR}"; gimptool --build ${DISTNAME}${EXTRACT_SUFX}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME} \
		${PREFIX}/lib/gimp/2.0/plug-ins/fix-ca

.include "../../graphics/gimp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
