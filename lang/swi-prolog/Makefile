# $NetBSD: Makefile,v 1.7 2001/04/29 16:01:16 jtb Exp $

DISTNAME=		pl-lite-4.0.4
PKGNAME=		swi-prolog-4.0.4
CATEGORIES=		lang
MASTER_SITES=		http://www.swi.psy.uva.nl/cgi-bin//nph-download/SWI-Prolog/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.swi.psy.uva.nl/projects/SWI-Prolog/
COMMENT=		ISO/Edinburgh-style Prolog compiler

DEPENDS+=		readline>=4.0:../../devel/readline

WRKSRC=			${WRKDIR}/${DISTNAME:S,-lite,,}
DIST_SUBDIR=		swi-prolog

GNU_CONFIGURE=		yes

USE_CURSES=		yes
REPLACE_NCURSES=	${WRKSRC}/src/configure

SWIPL=			swi-prolog
CONFIGURE_ENV+=		PL="${SWIPL}"
CPPFLAGS+=		-D__unix__=1

EVAL_PREFIX+=		READLINE_PREFIX=readline
CPPFLAGS+=		-I${READLINE_PREFIX}/include
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

PLIST_SUBST+=		SWIPL=${SWIPL}
PLIST_SUBST+=		SWILIBDIR=${DISTNAME:S,pl-lite,'${SWIPL}',}

.include "../../mk/bsd.pkg.mk"
