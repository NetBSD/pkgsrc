# $NetBSD: Makefile,v 1.1.1.1 2001/02/20 20:03:53 jtb Exp $

DISTNAME=		pl-lite-4.0.0
PKGNAME=		swi-prolog-4.0.0
CATEGORIES=		lang
MASTER_SITES=		http://www.swi.psy.uva.nl/cgi-bin//nph-download/SWI-Prolog/

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://www.swi.psy.uva.nl/projects/SWI-Prolog/
COMMENT=		ISO/Edinburgh-style Prolog compiler

DEPENDS+=		readline-[0-9]*:../../devel/readline
BUILD_DEPENDS+=		${LOCALBASE}/bin/autoconf:../../devel/autoconf

WRKSRC=			${WRKDIR}/${DISTNAME:S,-lite,,}
DIST_SUBDIR=		swi-prolog

USE_CURSES=		#defined
REPLACE_NCURSES=	${WRKSRC}/src/configure

GNU_CONFIGURE=		#defined
CONFIGURE_ENV+=		"BUILDARCH=${MACHINE_PLATFORM}"
SWIPL=			swi-prolog
CONFIGURE_ENV+=		"PL=${SWIPL}"
CPPFLAGS+=		-D__unix__=1
CONFIGURE_ENV+=		"CPPFLAGS=${CPPFLAGS}"

PLIST_SUBST+=		SWIPL=${SWIPL}
PLIST_SUBST+=		SWILIBDIR=${DISTNAME:S,pl,'${SWIPL}',}

pre-configure:
	cd ${WRKSRC}/src && ${LOCALBASE}/bin/autoconf

.include "../../mk/bsd.pkg.mk"
