# $NetBSD: Makefile,v 1.4 2004/04/24 22:25:31 wiz Exp $
#

.include "../../multimedia/libflash/Makefile.common"

PKGNAME=	moz-flash-1.0
PKGREVISION=	4
CATEGORIES+=	www

MAINTAINER=	joda@NetBSD.org
COMMENT=	Mozilla open source Flash(tm) plugin

DEPENDS+=	mozilla>=0.9.9:../../www/mozilla

USE_BUILDLINK3=	YES
USE_X11=	YES
USE_LIBTOOL=	YES

BUILD_DIRS=	${WRKSRC}/Plugin
CPPFLAGS+=	-DDEV_DSP=\\\"${DEVOSSSOUND}\\\"
MAKE_ENV+=	SHLIBTOOL="${SHLIBTOOL}"
MAKE_ENV+=	MOZ_PLUGDIR="${MOZ_PLUGDIR}"

MOZ_PLUGDIR=	${PREFIX}/lib/mozilla/plugins

do-install:
	${INSTALL_DATA_DIR} ${MOZ_PLUGDIR}
	cd ${WRKSRC}/Plugin && \
		${INSTALL_PROGRAM} .libs/npflash.so ${MOZ_PLUGDIR}

.include "../../multimedia/libflash/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
