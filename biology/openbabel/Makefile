# $NetBSD: Makefile,v 1.37 2020/03/08 16:48:52 wiz Exp $
#

GITHUB_PROJECT=	openbabel
DISTNAME=	openbabel-${RELVERSION:S/-/./g}
PKGREVISION=	2
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=openbabel/}
GITHUB_TAG=	${PKGBASE}-${RELVERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://openbabel.org/
COMMENT=	Chemistry file translation program
LICENSE=	gnu-gpl-v2

RELVERSION=	3-0-0

USE_LANGUAGES=	c gnu++11
USE_TOOLS+=	pkg-config
USE_CMAKE=	yes

PKGCONFIG_OVERRIDE+=	openbabel-3.pc.cmake

.include "options.mk"

CONFIGURE_DIRS=		${WRKDIR}/build
CMAKE_ARG_PATH=		${WRKSRC}

CMAKE_ARGS+=	-DLLVM_CONFIG=${LLVM_CONFIG_PATH:Q}

post-extract:
	${MKDIR} ${WRKDIR}/build

.include "../../graphics/cairo/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../math/eigen2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
