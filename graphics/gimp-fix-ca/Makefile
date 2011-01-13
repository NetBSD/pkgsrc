# $NetBSD: Makefile,v 1.18 2011/01/13 13:38:03 wiz Exp $
#

DISTNAME=		gimp-fix-ca-3.0.1
PKGREVISION=		8
CATEGORIES=		graphics
MASTER_SITES=		http://registry.gimp.org/file/fix-ca.c?action=download&id=9884&file=
EXTRACT_SUFX=		.c

MAINTAINER=		dsainty@NetBSD.org
HOMEPAGE=		http://kcd.sourceforge.net/fix-ca.php
COMMENT=		GIMP plugin to correct chromatic aberration (CA)

PKG_DESTDIR_SUPPORT=	user-destdir

FETCH_BEFORE_ARGS+=	-o ${DISTNAME}${EXTRACT_SUFX}
WRKSRC=			${WRKDIR}
NO_CONFIGURE=		yes
INSTALLATION_DIRS=	lib/gimp/2.0/plug-ins

USE_TOOLS+=		pkg-config

LINK_PTHREAD=		${PTHREAD_LDFLAGS} ${PTHREAD_LIBS}

pre-build:
	ln -sf ${LOCALBASE}/bin/gimptool-2.0 \
		${BUILDLINK_DIR}/bin/gimptool

do-build:
	cd "${WRKDIR}" && \
	    LIBS=${LINK_PTHREAD:Q} gimptool --build ${DISTNAME}${EXTRACT_SUFX}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME} \
		${DESTDIR}${PREFIX}/lib/gimp/2.0/plug-ins/fix-ca

.include "../../graphics/gimp/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
