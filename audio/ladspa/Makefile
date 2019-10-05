# $NetBSD: Makefile,v 1.16 2019/10/05 17:39:38 nia Exp $

DISTNAME=	ladspa_sdk_1.15
PKGNAME=	${DISTNAME:S/_sdk_/-/}
CATEGORIES=	audio
MASTER_SITES=	https://www.ladspa.org/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ladspa.org/
COMMENT=	Linux Audio Developers Simple Plugin API
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/ladspa_sdk_${PKGVERSION_NOREV}

BUILD_DIRS=	src
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

MAKE_FILE=	Makefile
BUILD_TARGET=	targets
TEST_TARGET=	test

INSTALLATION_DIRS+=	bin include
INSTALLATION_DIRS+=	lib/ladspa
INSTALLATION_DIRS+=	share/doc/ladspa

do-install:
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DESTDIR}${PREFIX}/share/doc/ladspa
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/plugins/*.la ${DESTDIR}${PREFIX}/lib/ladspa
	${LIBTOOL} --mode=install ${INSTALL_DATA} ${WRKSRC}/src/ladspa.h ${DESTDIR}${PREFIX}/include
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${DESTDIR}${PREFIX}/bin

.include "../../mk/dlopen.buildlink3.mk"
LDFLAGS+=	${BUILDLINK_LDADD.dl}
.include "../../mk/bsd.pkg.mk"
