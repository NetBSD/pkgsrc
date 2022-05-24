# $NetBSD: Makefile,v 1.15 2022/05/24 12:58:54 nia Exp $
#

DISTNAME=	ibus-table-chinese-1.8.2
CATEGORIES=	inputmethod chinese
MASTER_SITES=	-https://github.com/definite/ibus-table-chinese/archive/${PKGVERSION_NOREV}.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ibus/ibus/wiki
COMMENT=	Chinese tables for IBus-Table
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

BUILD_DEPENDS+=	cmake-fedora>=2.0:../../devel/cmake-fedora

# iconv: unexpected end of file; the last character is incomplete.
MAKE_JOBS_SAFE=	no

.include "../../mk/bsd.prefs.mk"

# Illegal byte sequence in array30_ExtB.txt
.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 050000
BUILD_DEPENDS+=		libiconv-[0-9]*:../../converters/libiconv
CMAKE_ARGS+=		-DICONV_CMD:PATH=${LOCALBASE}/bin/iconv
.endif

.include "../../inputmethod/ibus-table/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
