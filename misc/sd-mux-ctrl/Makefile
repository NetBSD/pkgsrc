# $NetBSD: Makefile,v 1.1 2020/08/03 18:27:49 jmcneill Exp $

PKGNAME=	sd-mux-ctrl-0.0.20200217
DISTNAME=	sd-mux-9dd189d973da64e033a0c5c2adb3d94b23153d94
CATEGORIES=	misc
MASTER_SITES=	https://git.tizen.org/cgit/tools/testlab/sd-mux/snapshot/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmcneill@invisible.ca
HOMEPAGE=	https://wiki.tizen.org/SD_MUX
COMMENT=	Control software for sd-mux devices
LICENSE=	apache-2.0

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/man/sd-mux-ctrl.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/libftdi1/buildlink3.mk"
BUILDLINK_API_DEPENDS.libftdi1+=	libftdi1>=1.4
.include "../../devel/popt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
