# $NetBSD: Makefile,v 1.17 2002/10/25 17:58:33 wiz Exp $

DISTNAME=		pl-lite-5.0.5
PKGNAME=		swi-prolog-5.0.5
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.swi.psy.uva.nl/SWI-Prolog/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.swi-prolog.org
COMMENT=		ISO/Edinburgh-style Prolog compiler

WRKSRC=			${WRKDIR}/${DISTNAME:S,-lite,,}
DIST_SUBDIR=		swi-prolog

GNU_CONFIGURE=		# defined
USE_BUILDLINK2=		# defined
USE_GNU_READLINE=	# uses rl_event_hook() interface

SWIPL=			swi-prolog
CONFIGURE_ENV+=		PL="${SWIPL}"
CPPFLAGS+=		-D__unix__=1

PLIST_SUBST+=		SWIPL=${SWIPL}
PLIST_SUBST+=		SWILIBDIR=${DISTNAME:S,pl-lite,'${SWIPL}',}
PLIST_SUBST+=		APPEND_ELF=${APPEND_ELF}

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == alpha || ${MACHINE_ARCH} == sparc64
PLIST_SUBST+=		BITS=64
.else
PLIST_SUBST+=		BITS=32
.endif

.include "../../devel/ncurses/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
