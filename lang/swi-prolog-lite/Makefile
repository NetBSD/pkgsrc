# $NetBSD: Makefile,v 1.27 2018/09/06 19:07:12 leot Exp $

PKGREVISION= 2
.include "Makefile.common"

PKGNAME=		swi-prolog-lite-${SWIPLVERS}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		ISO/Edinburgh-style Prolog compiler

GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		src

CONFIGURE_ENV+=		PL=swi-prolog
CONFIGURE_ENV+=		PLARCH=${MACHINE_GNU_PLATFORM}	# make PLIST consistent
USE_TOOLS+=		gmake bash:run

.include "../../mk/bsd.prefs.mk"

.if !empty(LP64PLATFORMS:@.PLAT.@${MACHINE_PLATFORM:M${.PLAT.}}@) || \
    (defined(ABI) && ${ABI} == "64")
PLIST_SUBST+=		BITS=64
.else
PLIST_SUBST+=		BITS=32
.endif

REPLACE_INTERPRETER+=	swipl
REPLACE.swipl.old=	/usr/bin/swipl
REPLACE.swipl.new=	${PREFIX}/bin/swi-prolog
REPLACE_FILES.swipl+=	library/dialect/sicstus/swipl-lfr.pl

TEST_TARGET=		check

.include "../../devel/ncurses/buildlink3.mk"
# uses rl_event_hook() interface
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
