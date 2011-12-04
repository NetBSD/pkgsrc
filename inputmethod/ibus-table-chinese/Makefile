# $NetBSD: Makefile,v 1.5 2011/12/04 13:28:00 obache Exp $
#

DISTNAME=	ibus-table-chinese-1.3.5-Source-Standalone
PKGNAME=	${DISTNAME:S/-Source-Standalone//}
CATEGORIES=	inputmethod chinese
MASTER_SITES=	http://ibus.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus/
COMMENT=	Chinese tables for IBus-Table
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${DISTNAME:S/-Standalone//}

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

# Illegal byte sequence in array30_ExtB.txt
CHECK_BUILTIN.iconv:=	yes
.include "../../converters/libiconv/builtin.mk"
CHECK_BUILTIN.iconv:=	no
.if ${ICONV_TYPE} != "gnu" || !exists(/usr/bin/iconv)
BUILD_DEPENDS+=		libiconv-[0-9]*:../../converters/libiconv
FIND_PREFIX:= ICONV_PREFIX=libiconv
.include "../../mk/find-prefix.mk"
.else
ICONV_PREFIX=/usr
.endif

CMAKE_ARGS+=	-DICONV_CMD:PATH=${ICONV_PREFIX}/bin/iconv

.include "../../inputmethod/ibus-table/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
