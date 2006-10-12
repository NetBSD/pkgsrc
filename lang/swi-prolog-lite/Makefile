# $NetBSD: Makefile,v 1.11 2006/10/12 14:14:13 joerg Exp $

.include "Makefile.common"

PKGNAME=		swi-prolog-lite-${SWIPLVERS}
PKGREVISION=		1

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		ISO/Edinburgh-style Prolog compiler

GNU_CONFIGURE=		yes
OVERRIDE_DIRDEPTH=	3
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
