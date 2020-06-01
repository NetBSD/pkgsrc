# $NetBSD: Makefile,v 1.3 2020/06/01 12:15:15 pin Exp $

VERSION=	0.15.0
DISTNAME=	lxqt-openssh-askpass-${VERSION}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxqt/lxqt-openssh-askpass/releases/download/${VERSION}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/lxqt-openssh-askpass/
COMMENT=	Tool used with openssh to prompt the user for a password
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

TOOL_DEPENDS+=	lxqt-build-tools-[0-9]*:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools
DEPENDS+=	openssh-[0-9]*:../../security/openssh

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/liblxqt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
