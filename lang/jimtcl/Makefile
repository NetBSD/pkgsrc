# $NetBSD: Makefile,v 1.14 2025/05/06 12:07:32 wiz Exp $

DISTNAME=	jimtcl-0.83
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=msteveb/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jim.tcl.tk/
COMMENT=	Small footprint implementation of the Tcl programming language
LICENSE=	2-clause-bsd

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}
CONFIGURE_ARGS+=	--docdir=${PREFIX}/share/doc/jimtcl
CONFIGURE_ARGS+=	--full # Enable optional features
CONFIGURE_ARGS+=	--shared
CONFIGURE_ARGS+=	--disable-jim-regexp
CONFIGURE_ARGS+=	--compat # Support older expr syntax for openocd

# Disable ccache; see autosetup/cc.tcl
CONFIGURE_ENV+=		CCACHE=none

REPLACE_INTERPRETER+=	jimsh
REPLACE.jimsh.old=	/usr/bin/env jimsh
REPLACE.jimsh.new=	${PREFIX}/bin/jimsh
REPLACE_FILES.jimsh=	build-jim-ext.in jimdb

TEST_TARGET=	test

OPSYSVARS+=	SHLIB_EXT SONAME
SONAME.Darwin=	libjim.${PKGVERSION_NOREV}.${SHLIB_EXT}
SONAME.*=	libjim.${SHLIB_EXT}.${PKGVERSION_NOREV}

PLIST_SUBST+=	SONAME=${SONAME}

post-install:
	${LN} -sf ${SONAME} ${DESTDIR}${PREFIX}/lib/libjim.${SHLIB_EXT}

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
