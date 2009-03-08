# $NetBSD: Makefile,v 1.6 2009/03/08 17:17:02 asau Exp $

PKGNAME=		fricas-1.0.5
DISTNAME=		${PKGNAME_NOREV}-full
PKGREVISION=		1
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fricas/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		asau@inbox.ru
HOMEPAGE=		http://fricas.sourceforge.net/
COMMENT=		FriCAS is a fork of the Axiom computer algebra system

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

BUILD_DEPENDS+=		noweb-[0-9]*:../../devel/noweb

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

# Problems:
# 4. Emacs files should go into "site-lisp".
# 5. view3D hangs sometimes (?), killing it doesn't affect binary package.

.include "options.mk"

.if !empty(PKG_OPTIONS:Mclisp)
INSTALL_UNSTRIPPED=	yes	# don't strip AXIOMsys, it breaks FFI
.endif

# Fix BSD Family pattern:
SUBST_CLASSES+=			dragonfly
SUBST_STAGE.dragonfly=		post-patch
SUBST_MESSAGE.dragonfly=	Fixing BSD Family pattern
SUBST_FILES.dragonfly=		configure
SUBST_SED.dragonfly=		-e 's/\*bsd\*)/*bsd*|*dragonfly*)/'

.include "../../mk/bsd.pkg.mk"
