# $NetBSD: Makefile,v 1.1.1.1 2003/07/19 08:59:12 wiz Exp $
#

DISTNAME=	flac-1.1.0
PKGNAME=	xmms-flac-1.1.0
PKGREVISION=	2
CATEGORIES=	audio archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=flac/}

MAINTAINER=	collver1@comcast.net
HOMEPAGE=	http://flac.sourceforge.net/
COMMENT=	FLAC XMMS plugin

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
SHLIBTOOL_OVERRIDE=	${WRKSRC}/libtool-disable-static

XMMS_WRKSRC=	${WRKSRC}/src/plugin_xmms

# previous name of the package
CONFLICTS=	flac-xmms-[0-9]*

#do-build:
#	@cd ${XMMS_WRKSRC}/../plugin_common && ${SETENV} ${MAKE_ENV} \
#		${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${ALL_TARGET}
#	@cd ${XMMS_WRKSRC} && ${SETENV} ${MAKE_ENV} \
#		${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${ALL_TARGET}

do-install:
	@cd ${XMMS_WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${INSTALL_TARGET}

.include "../../audio/flac/buildlink2.mk"
.include "../../audio/xmms/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
