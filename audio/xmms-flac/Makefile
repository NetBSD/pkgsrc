# $NetBSD: Makefile,v 1.12 2005/03/03 15:29:52 wiz Exp $
#

DISTNAME=	flac-1.1.2
PKGNAME=	xmms-flac-1.1.2
CATEGORIES=	audio archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=flac/}

MAINTAINER=	ben@NetBSD.org
HOMEPAGE=	http://flac.sourceforge.net/
COMMENT=	FLAC XMMS plugin

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes

USE_LIBTOOL=		yes
SHLIBTOOL_OVERRIDE=	libtool-disable-static

XMMS_WRKSRC=	${WRKSRC}/src/plugin_xmms

# previous name of the package
CONFLICTS=	flac-xmms-[0-9]*

#do-build:
#	@cd ${XMMS_WRKSRC}/../plugin_common && ${SETENV} ${MAKE_ENV} \
#		${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${BUILD_TARGET}
#	@cd ${XMMS_WRKSRC} && ${SETENV} ${MAKE_ENV} \
#		${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${BUILD_TARGET}

do-install:
	@cd ${XMMS_WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${INSTALL_TARGET}

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
