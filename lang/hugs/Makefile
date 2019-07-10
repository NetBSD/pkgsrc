# $NetBSD: Makefile,v 1.44 2019/07/10 10:24:05 nia Exp $

DISTNAME=	hugs98-Sep2006
PKGNAME=	hugs98-200609
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://cvs.haskell.org/Hugs/downloads/2006-09/

MAINTAINER=	nathanw@mit.edu
HOMEPAGE=	https://www.haskell.org/hugs/
COMMENT=	Functional programming system based on Haskell 98
LICENSE=	modified-bsd

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake bison

CONFIGURE_ARGS+=	--build=${MACHINE_GNU_PLATFORM:Q}
CONFIGURE_ARGS+=	--target=${MACHINE_GNU_PLATFORM:Q}

PKG_OPTIONS_VAR=	PKG_OPTIONS.hugs
PKG_SUGGESTED_OPTIONS=	readline
PKG_SUPPORTED_OPTIONS=	readline

.include "../../mk/bsd.options.mk"

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
BUILD_DEPENDS+=		tradcpp-[0-9]*:../../devel/tradcpp
CONFIGURE_ARGS+=	ice_cv_traditional_cpp=${PREFIX}/bin/tradcpp
.endif

.if !empty(PKG_OPTIONS:Mreadline)
.  include "../../mk/readline.buildlink3.mk"
.else
CONFIGURE_ARGS+=	ac_cv_lib_readline_readline=no
.endif

.include "../../mk/bsd.pkg.mk"

# The default -O2 breaks the interpreter producing strange internal errors
# at run time.
.if !empty(CC_VERSION:Mgcc-4*)
CFLAGS+=    -O0
.endif
