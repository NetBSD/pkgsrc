# $NetBSD: Makefile,v 1.9 2023/03/02 23:11:58 fcambus Exp $

DISTNAME=	jimtcl-0.82
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

REPLACE_INTERPRETER+=	jimsh
REPLACE.jimsh.old=	/usr/bin/env jimsh
REPLACE.jimsh.new=	${PREFIX}/bin/jimsh
REPLACE_FILES.jimsh=	build-jim-ext.in jimdb

TEST_TARGET=	test

OPSYSVARS+=	SOEXT SONAME
SOEXT.Darwin=	dylib
SONAME.Darwin=	libjim.${PKGVERSION_NOREV}.${SOEXT}
SOEXT.*=	so
SONAME.*=	libjim.${SOEXT}.${PKGVERSION_NOREV}

PLIST_SUBST+=	SOEXT=${SOEXT} SONAME=${SONAME}

post-install:
	${LN} -sf ${SONAME} ${DESTDIR}${PREFIX}/lib/libjim.${SOEXT}

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
