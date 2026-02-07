# $NetBSD: Makefile,v 1.4 2026/02/07 08:31:18 wiz Exp $

DISTNAME=	sd-mux-9dd189d973da64e033a0c5c2adb3d94b23153d94
PKGNAME=	sd-mux-ctrl-0.0.20200217
CATEGORIES=	misc
#MASTER_SITES=	https://git.tizen.org/cgit/tools/testlab/sd-mux/snapshot/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmcneill@invisible.ca
#HOMEPAGE=	https://wiki.tizen.org/SD_MUX
COMMENT=	Control software for sd-mux devices
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5
INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/man/sd-mux-ctrl.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/cmake/build.mk"
.include "../../devel/libftdi1/buildlink3.mk"
BUILDLINK_API_DEPENDS.libftdi1+=	libftdi1>=1.4
.include "../../devel/popt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
