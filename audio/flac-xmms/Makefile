# $NetBSD: Makefile,v 1.5 2002/09/06 06:45:07 jlam Exp $
#

DISTNAME=	flac-1.0.3
PKGNAME=	flac-xmms-1.0.3
CATEGORIES=	audio archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=flac/}

MAINTAINER=	collver@linuxfreemail.com
HOMEPAGE=	http://flac.sourceforge.net/
COMMENT=	FLAC XMMS plugin

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

XMMS_WRKSRC=	${WRKSRC}/src/plugin_xmms

do-build:
	@cd ${XMMS_WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${ALL_TARGET}

do-install:
	@cd ${XMMS_WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${INSTALL_TARGET}

.include "../../audio/flac/buildlink2.mk"
.include "../../audio/xmms/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
