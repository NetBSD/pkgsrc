# $NetBSD: Makefile,v 1.6 2021/05/06 15:19:39 tnn Exp $

DISTNAME=	jimtcl-0.80
PKGREVISION=	1
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

REPLACE_INTERPRETER+=	jimsh
REPLACE.jimsh.old=	/usr/bin/env jimsh
REPLACE.jimsh.new=	${PREFIX}/bin/jimsh
REPLACE_FILES.jimsh=	build-jim-ext.in

TEST_TARGET=	test

post-install:
	${LN} -sf libjim.so.${PKGVERSION_NOREV} ${DESTDIR}${PREFIX}/lib/libjim.so

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
