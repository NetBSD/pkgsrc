# $NetBSD: Makefile,v 1.3 2004/10/03 00:15:02 tv Exp $

.include "Makefile.common"

PKGNAME=		swi-prolog-lite-${SWIPLVERS}
PKGREVISION=	1

MAINTAINER=		hubertf@NetBSD.org
COMMENT=		ISO/Edinburgh-style Prolog compiler

GNU_CONFIGURE=		# defined
USE_BUILDLINK3=		yes
USE_BUILTIN.readline=	no	# uses rl_event_hook() interface

CONFIGURE_ENV+=		PL=swi-prolog
CONFIGURE_ARGS+=	--disable-mt
#CPPFLAGS+=		-DPREFIX=\"${PREFIX}\"
#CPPFLAGS+=		-DSWIPLVERS=\"${SWIPLVERS}\"

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == alpha || ${MACHINE_ARCH} == sparc64 || \
	${MACHINE_ARCH} == x86_64
PLIST_SUBST+=		BITS=64
.else
PLIST_SUBST+=		BITS=32
.endif

post-install:
	${INSTALL_DATA} ${FILESDIR}/shlib.pl \
		${PREFIX}/lib/swi-prolog-${PKGVERSION}/library/shlib.pl

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
#.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
