# $NetBSD: Makefile,v 1.8 2003/01/30 14:47:06 jlam Exp $
#

.include "../libflash/Makefile.common"

PKGNAME=	moz-flash-1.0
PKGREVISION=	2

MAINTAINER=	joda@netbsd.org
COMMENT=	Mozilla open source Flash(tm) plugin

DEPENDS+=	mozilla>=0.9.9:../../www/mozilla

USE_BUILDLINK2=	yes
USE_X11BASE=	yes
USE_LIBTOOL=	yes
BUILD_DIRS=	${WRKSRC}/Plugin
CPPFLAGS+=	-DDEV_DSP=\\\"${DEVOSSSOUND}\\\"
MAKE_ENV+=	SHLIBTOOL="${PKGSHLIBTOOL}"
MAKE_ENV+=	MOZ_PLUGDIR="${MOZ_PLUGDIR}"

MOZ_PLUGDIR=	${PREFIX}/lib/mozilla/plugins

do-install:
	cd ${WRKSRC}/Plugin && \
		${INSTALL_PROGRAM} .libs/npflash.so ${MOZ_PLUGDIR}

.include "../libflash/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
