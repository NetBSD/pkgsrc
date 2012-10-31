# $NetBSD: Makefile,v 1.3 2012/10/31 11:19:55 asau Exp $
#

DISTNAME=	zzuf-0.13
CATEGORIES=	devel security
MASTER_SITES=	http://caca.zoy.org/files/zzuf/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://caca.zoy.org/wiki/zzuf/
COMMENT=	Transparent application input fuzzer

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

BUILDLINK_TRANSFORM+=	l:gnugetopt:getopt
SHLIBTOOL_OVERRIDE=	# empty

SUBST_CLASSES+=		fix-paths
SUBST_FILES.fix-paths=	doc/libzzuf.3.in
SUBST_MESSAGE.fix-paths=Fixing hard-coded pathnames
SUBST_SED.fix-paths=	-e 's,/usr,${PREFIX},g'
SUBST_STAGE.fix-paths=	post-patch

.include "../../mk/bsd.fast.prefs.mk"

LIBS.NetBSD+=	${NETBSDLIB.rt}
###
### XXX Do this with autoconf?
###
.if ${OPSYS} == "NetBSD" && exists(/usr/include/aio.h)
.PHONY: netbsd-posix-aio-check
netbsd-posix-aio-check:
NETBSDLIB.rt!=								\
	if ( /sbin/sysctl -n kern.posix_aio >/dev/null 2>&1 ); then	\
	    lib=-lrt;							\
	fi || ${TRUE};							\
	echo "$$lib"
.endif

TEST_TARGET=	check

.include "options.mk"

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
