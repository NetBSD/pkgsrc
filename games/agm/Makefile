# $NetBSD: Makefile,v 1.1 2016/07/27 20:37:27 kamil Exp $

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

.include "../../mk/bsd.pkg.mk"
