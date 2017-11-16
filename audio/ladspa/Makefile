# $NetBSD: Makefile,v 1.14 2017/11/16 15:05:31 khorben Exp $

DISTNAME=	ladspa_sdk_1.13
PKGNAME=	${DISTNAME:S/_sdk_/-/}
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.ladspa.org/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ladspa.org/
COMMENT=	Linux Audio Developers Simple Plugin API
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/ladspa_sdk/src
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

MAKE_FILE=	makefile

BUILDLINK_LIBS.dl+=	${BUILDLINK_LDADD.dl}

INSTALLATION_DIRS+=	bin include lib

MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}

#XXX does not work (No rule to make target 'targets')
#do-test:
#	cd ${WRKSRC} && && ${BUILD_MAKE_CMD} test

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
