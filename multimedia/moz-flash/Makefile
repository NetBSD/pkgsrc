# $NetBSD: Makefile,v 1.1.1.1 2004/01/26 14:48:23 jmmv Exp $
#

.include "../../multimedia/libflash/Makefile.common"

PKGNAME=	moz-flash-1.0
PKGREVISION=	4

MAINTAINER=	joda@NetBSD.org
COMMENT=	Mozilla open source Flash(tm) plugin

DEPENDS+=	mozilla>=0.9.9:../../www/mozilla

USE_BUILDLINK2=	YES
USE_X11=	YES
USE_LIBTOOL=	YES

BUILD_DIRS=	${WRKSRC}/Plugin
CPPFLAGS+=	-DDEV_DSP=\\\"${DEVOSSSOUND}\\\"
MAKE_ENV+=	SHLIBTOOL="${PKGSHLIBTOOL}"
MAKE_ENV+=	MOZ_PLUGDIR="${MOZ_PLUGDIR}"

MOZ_PLUGDIR=	${PREFIX}/lib/mozilla/plugins

do-install:
	${INSTALL_DATA_DIR} ${MOZ_PLUGDIR}
	cd ${WRKSRC}/Plugin && \
		${INSTALL_PROGRAM} .libs/npflash.so ${MOZ_PLUGDIR}

.include "../../multimedia/libflash/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
