# $NetBSD: Makefile,v 1.13 2001/07/15 12:27:38 jtb Exp $

DISTNAME=		pl-lite-4.0.9
PKGNAME=		swi-prolog-4.0.9
CATEGORIES=		lang
MASTER_SITES=		http://www.swi.psy.uva.nl/cgi-bin//nph-download/SWI-Prolog/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.swi.psy.uva.nl/projects/SWI-Prolog/
COMMENT=		ISO/Edinburgh-style Prolog compiler

WRKSRC=			${WRKDIR}/${DISTNAME:S,-lite,,}
DIST_SUBDIR=		swi-prolog

GNU_CONFIGURE=		# defined
USE_BUILDLINK_ONLY=	# defined
USE_GNU_READLINE=	# uses rl_event_hook() interface

SWIPL=			swi-prolog
CONFIGURE_ENV+=		PL="${SWIPL}"
CPPFLAGS+=		-D__unix__=1

PLIST_SUBST+=		SWIPL=${SWIPL}
PLIST_SUBST+=		SWILIBDIR=${DISTNAME:S,pl-lite,'${SWIPL}',}

.include "../../devel/ncurses/buildlink.mk"
.include "../../devel/readline/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
