# $NetBSD: Makefile,v 1.43 2009/12/15 13:53:24 asau Exp $

DISTNAME=		otp_src_${DIST_VERSION_MAJOR}${DIST_VERSION_MINOR:D-${DIST_VERSION_MINOR}}
PKGNAME=		erlang-${ERLANG_VERSION}
PKGREVISION=		2
CATEGORIES=		lang
MASTER_SITES=		http://www.erlang.org/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.erlang.org/
COMMENT=		Concurrent functional programming language

DIST_SUBDIR=		erlang

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=		yes
USE_GNU_CONFIGURE_HOST=	${USE_CROSS_COMPILE}
OVERRIDE_DIRDEPTH=	4
USE_TOOLS+=		gmake perl:run

CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}

###
### XXX Linking fails on amd64 due to invalid relocations without this.
###
CONFIGURE_ARGS+=	--enable-dynamic-ssl-lib

PTHREAD_OPTS+=		require native
CONFIGURE_ARGS+=	--enable-threads

MAKE_ENV+=		DESTDIR=${DESTDIR}

SUBST_CLASSES+=		target
SUBST_STAGE.target=	post-patch
SUBST_FILES.target=	make/target.mk
SUBST_SED.target=	-e "s|=.*config.guess)|= ${MACHINE_GNU_PLATFORM}|"
SUBST_MESSAGE.target=	Fixing target name.

TEST_TARGET=		tests
TEST_MAKE_FLAGS=	ERL_TOP=$(WRKSRC)
REPLACE_PERL+=		make/make_emakefile

PLIST_SRC=		PLIST

.include "../../mk/bsd.prefs.mk"

.if exists(${.CURDIR}/PLIST.${OPSYS})
PLIST_SRC+=	${.CURDIR}/PLIST.${OPSYS}
.endif

.if ${OPSYS} == "DragonFly"
CONFIGURE_ARGS+=	--disable-sctp
.endif
###
### XXX There may be others here.
###
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD"
CONFIGURE_ARGS+=	--enable-kernel-poll
.endif

.include "options.mk"

.include "Makefile.versions"

###
### Ensure this gets rebuilt.
###
pre-build:
	${RUN} ${RM} -f ${WRKSRC}/lib/stdlib/ebin/dets_v9.beam

post-install:
	chmod -R go-w ${DESTDIR}${PREFIX}/lib/erlang/lib

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
