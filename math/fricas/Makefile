# $NetBSD: Makefile,v 1.25 2016/03/12 20:54:23 asau Exp $

PKGNAME=		fricas-1.2.7
DISTNAME=		${PKGNAME_NOREV}-full
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fricas/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		asau@inbox.ru
HOMEPAGE=		http://fricas.sourceforge.net/
COMMENT=		FriCAS is a fork of the Axiom computer algebra system
LICENSE=		modified-bsd

MAKE_JOBS_SAFE=		no

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

# Problems:
# 4. Emacs files should go into "site-lisp".

.include "options.mk"

.if !empty(PKG_OPTIONS:Mclisp)
# Don't strip, it breaks FFI:
INSTALL_UNSTRIPPED=	yes
CHECK_WRKREF_SKIP=	lib/*/hypertex lib/*/viewAlone lib/*/view2D lib/*/view3D lib/*/viewman
.endif

.include "../../mk/bsd.pkg.mk"
