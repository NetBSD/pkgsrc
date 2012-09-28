# $NetBSD: Makefile,v 1.19 2012/09/28 07:58:06 sbd Exp $

.include "Makefile.common"

PKGNAME=		swi-prolog-lite-${SWIPLVERS}
PKGREVISION=		1

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		ISO/Edinburgh-style Prolog compiler

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		src
USE_GNU_READLINE=	yes # uses rl_event_hook() interface

CONFIGURE_ENV+=		PL=swi-prolog
CONFIGURE_ENV+=		ARCH=${MACHINE_GNU_PLATFORM}	# make PLIST consistent
USE_TOOLS+=		gmake bash:run
REPLACE_BASH+=		dotfiles/edit

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == alpha || ${MACHINE_ARCH} == sparc64 || \
	${MACHINE_ARCH} == x86_64
PLIST_SUBST+=		BITS=64
.else
PLIST_SUBST+=		BITS=32
.endif

REPLACE_INTERPRETER+=	swipl
REPLACE.swipl.old=	/usr/bin/swipl
REPLACE.swipl.new=	${PREFIX}/bin/swi-prolog
REPLACE_FILES.swipl+=	library/dialect/sicstus/swipl-lfr.pl

TEST_TARGET=		check

post-install:
	${INSTALL_DATA} ${FILESDIR}/shlib.pl \
		${DESTDIR}${PREFIX}/lib/swi-prolog-${SWIPLVERS}/library/shlib.pl

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
