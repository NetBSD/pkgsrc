# $NetBSD: Makefile,v 1.2 2026/08/04 20:28:55 wiz Exp $

DISTNAME=	agm-1.3.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE:=games/amusements/}

MAINTAINER=	pkgsrc-users@NetBSD.org
# Nothing better available
HOMEPAGE=	${MASTER_SITE_SUNSITE:=games/amusements/}
COMMENT=	Multiple-word anagram search program
LICENSE=	generic-nonlicense

SUBST_CLASSES+=		rcsids
SUBST_MESSAGE.rcsids=	Strip RCS IDs as they cause problems when patching.
SUBST_STAGE.rcsids=	pre-patch
SUBST_FILES.rcsids+=	agm.h
SUBST_FILES.rcsids+=	gobble.c
SUBST_FILES.rcsids+=	listfuncs.c
SUBST_FILES.rcsids+=	main.c
SUBST_FILES.rcsids+=	output.c
SUBST_FILES.rcsids+=	process.c
SUBST_FILES.rcsids+=	progress.c
SUBST_FILES.rcsids+=	sort.c
SUBST_FILES.rcsids+=	wordfuncs.c
SUBST_SED.rcsids=	-e "s!.Revision: !Revision: !"

MAKE_FLAGS+=	BINDIR=${PREFIX}/bin
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=	WORDDIR=${PREFIX}/share/agm
MAKE_FLAGS+=	CC=${CC:Q}

INSTALL_TARGET=		install install-words

REPLACE_INTERPRETER+=	wish
REPLACE.wish.old=	/usr/bin/wish
REPLACE.wish.new=	${PREFIX}/bin/wish
REPLACE_FILES.wish=	xagm

DEPENDS+=	tk-[0-9]*:../../x11/tk

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
