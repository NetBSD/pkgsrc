# $NetBSD: Makefile,v 1.34 2026/07/31 06:58:29 wen Exp $

DISTNAME=		${PKGNAME_NOREV}-full
PKGNAME=		fricas-1.3.13
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fricas/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		asau@inbox.ru
HOMEPAGE=		https://fricas.sourceforge.net/
COMMENT=		Fork of the Axiom computer algebra system
LICENSE=		modified-bsd

MAKE_JOBS_SAFE=		no

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

# XXX: this file is not PIE
CHECK_PIE_SKIP=		lib/fricas/target/*/bin/AXIOMsys

# Problems:
# 4. Emacs files should go into "site-lisp".

.include "options.mk"

.if !empty(PKG_OPTIONS:Mclisp)
# Don't strip, it breaks FFI:
INSTALL_UNSTRIPPED=	yes
CHECK_WRKREF_SKIP=	lib/*/hypertex lib/*/viewAlone lib/*/view2D lib/*/view3D lib/*/viewman
.endif

.include "../../mk/bsd.pkg.mk"
