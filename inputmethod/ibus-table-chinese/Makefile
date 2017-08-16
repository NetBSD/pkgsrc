# $NetBSD: Makefile,v 1.14 2017/08/16 21:22:13 wiz Exp $
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
MAKE_JOBS_SAFE=	noo

.include "../../mk/bsd.prefs.mk"

# Illegal byte sequence in array30_ExtB.txt
.if !empty(MACHINE_PLATFORM:MNetBSD-[0-5].*-*)
BUILD_DEPENDS+=		libiconv-[0-9]*:../../converters/libiconv
CMAKE_ARGS+=		-DICONV_CMD:PATH=${LOCALBASE}/bin/iconv
.endif

.include "../../inputmethod/ibus-table/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
