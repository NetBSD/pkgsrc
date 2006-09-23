# $NetBSD: Makefile,v 1.35 2006/09/23 13:36:06 joerg Exp $

DISTNAME=	hugs98-May2006
PKGNAME=	hugs98-200605
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://cvs.haskell.org/Hugs/downloads/2006-05/

MAINTAINER=	nathanw@mit.edu
HOMEPAGE=	http://www.haskell.org/hugs/
COMMENT=	Functional programming system based on Haskell 98

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake bison

CONFIGURE_ARGS+=	--build=${MACHINE_GNU_PLATFORM:Q}
CONFIGURE_ARGS+=	--target=${MACHINE_GNU_PLATFORM:Q}

PKG_OPTIONS_VAR=	PKG_OPTIONS.hugs
PKG_SUGGESTED_OPTIONS=	readline
PKG_SUPPORTED_OPTIONS=	readline

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mreadline)
.  include "../../devel/readline/buildlink3.mk"
.else
CONFIGURE_ARGS+=	ac_cv_lib_readline_readline=no
.endif

.include "../../mk/bsd.pkg.mk"

# The default -O2 breaks the interpreter producing strange internal errors
# at run time.
.if !empty(CC_VERSION:Mgcc-4*)
CFLAGS+=    -O0
.endif
