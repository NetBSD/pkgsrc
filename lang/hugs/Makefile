# $NetBSD: Makefile,v 1.33 2006/08/01 14:33:59 jmmv Exp $

DISTNAME=	hugs98-May2006
PKGNAME=	hugs98-200605
CATEGORIES=	lang
MASTER_SITES=	http://cvs.haskell.org/Hugs/downloads/2006-05/

MAINTAINER=	nathanw@mit.edu
HOMEPAGE=	http://www.haskell.org/hugs/
COMMENT=	Functional programming system based on Haskell 98

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

CONFIGURE_ARGS+=	--build=${MACHINE_GNU_PLATFORM:Q}
CONFIGURE_ARGS+=	--target=${MACHINE_GNU_PLATFORM:Q}

.include "../../mk/bsd.pkg.mk"

# The default -O2 breaks the interpreter producing strange internal errors
# at run time.
.if !empty(CC_VERSION:Mgcc-4*)
CFLAGS+=    -O0
.endif
