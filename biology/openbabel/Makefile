# $NetBSD: Makefile,v 1.35 2019/11/20 17:02:12 kamil Exp $
#

GITHUB_PROJECT=	openbabel
DISTNAME=	openbabel-${RELVERSION:S/-/./g}
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
