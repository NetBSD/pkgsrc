# $NetBSD: Makefile,v 1.33 2017/08/24 20:03:21 adam Exp $

PKGREVISION= 4
.include "../../graphics/exiv2/Makefile.common"

PKGNAME=	${DISTNAME:S/exiv2/exiv2-organize/}

USE_LANGUAGES+=		c++0x
USE_TOOLS+=		pkg-config
BUILD_DIRS=		contrib/organize
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/contrib/organize/organize \
		${DESTDIR}${PREFIX}/bin/exiv2-organize

.include "../../graphics/exiv2/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
