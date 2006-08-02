# $NetBSD: Makefile,v 1.10 2006/08/02 15:15:36 kristerw Exp $

.include "Makefile.common"

PKGNAME=		swi-prolog-lite-${SWIPLVERS}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		ISO/Edinburgh-style Prolog compiler

GNU_CONFIGURE=		yes
USE_GNU_READLINE=	yes # uses rl_event_hook() interface

CONFIGURE_ENV+=		PL=swi-prolog
CONFIGURE_ARGS+=	--disable-mt
USE_TOOLS+=		gmake
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
		${PREFIX}/lib/swi-prolog-${SWIPLVERS}/library/shlib.pl

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
#.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
