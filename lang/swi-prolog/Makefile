# $NetBSD: Makefile,v 1.26 2004/01/20 12:19:18 agc Exp $

DISTNAME=		pl-lite-5.0.10
PKGNAME=		swi-prolog-5.0.10
PKGREVISION=				1
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.swi.psy.uva.nl/SWI-Prolog/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.swi-prolog.org/
COMMENT=		ISO/Edinburgh-style Prolog compiler

DIST_SUBDIR=		swi-prolog
WRKSRC=			${WRKDIR}/${DISTNAME:S,-lite,,}

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
