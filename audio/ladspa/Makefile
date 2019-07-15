# $NetBSD: Makefile,v 1.15 2019/07/15 22:58:50 nia Exp $

DISTNAME=	ladspa_sdk_1.13
PKGNAME=	${DISTNAME:S/_sdk_/-/}
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.ladspa.org/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ladspa.org/
COMMENT=	Linux Audio Developers Simple Plugin API
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=	yes

WRKSRC=		${WRKDIR}/ladspa_sdk/src
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

MAKE_FILE=	makefile

BUILDLINK_LIBS.dl+=	${BUILDLINK_LDADD.dl}


MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}

#do-test:
#	cd ${WRKSRC} && && ${BUILD_MAKE_CMD} test

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
