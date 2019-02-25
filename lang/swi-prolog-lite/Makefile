# $NetBSD: Makefile,v 1.29 2019/02/25 15:20:44 leot Exp $

.include "Makefile.common"

PKGNAME=		swi-prolog-lite-${SWIPLVERS}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		ISO/Edinburgh-style Prolog compiler

CMAKE_ARGS+=		-DSWIPL_INSTALL_MANPAGES=${PKGMANDIR}/man1
CMAKE_ARGS+=		-DSWIPL_PACKAGES_BASIC=ON
CMAKE_ARGS+=		-DSWIPL_PACKAGES_ARCHIVE=ON
CMAKE_ARGS+=		-DSWIPL_PACKAGES_SSL=ON
CMAKE_ARGS+=		-DSWIPL_PACKAGES_TERM=ON
CMAKE_ARGS+=		-DINSTALL_DOCUMENTATION=ON

# Part of swi-prolog-jpl
CMAKE_ARGS+=		-DSWIPL_PACKAGES_JAVA=OFF

# Part of swi-prolog-packages
CMAKE_ARGS+=		-DSWIPL_PACKAGES_X=OFF

USE_TOOLS+=		bash:run

.include "../../mk/bsd.prefs.mk"

.if !empty(LP64PLATFORMS:@.PLAT.@${MACHINE_PLATFORM:M${.PLAT.}}@) || \
    (defined(ABI) && ${ABI} == "64")
PLIST_SUBST+=		BITS=64
.else
PLIST_SUBST+=		BITS=32
.endif

REPLACE_INTERPRETER+=	swipl
REPLACE.swipl.old=	/usr/bin/swipl
REPLACE.swipl.new=	${PREFIX}/bin/swipl
REPLACE_FILES.swipl+=	library/dialect/sicstus/swipl-lfr.pl

# XXX: editline bindings seems limited and does not support completion, remove
# XXX: them in order to always use readline.pl.
post-install:
	${RM} ${DESTDIR}${PREFIX}/lib/swipl/lib/${MACHINE_GNU_PLATFORM}/libedit4pl.so || ${TRUE}
	${RM} ${DESTDIR}${PREFIX}/lib/swipl/library/editline.pl || ${TRUE}

TEST_TARGET=		check

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/ossp-uuid/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
