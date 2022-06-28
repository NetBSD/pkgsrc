# $NetBSD: Makefile,v 1.4 2022/06/28 11:34:10 wiz Exp $

DISTNAME=		OTP-${DIST_VERSION_MAJOR}.${DIST_VERSION_MINOR}${!empty(DIST_VERSION_PATCH):?.:}${DIST_VERSION_PATCH}
PKGNAME=		${DISTNAME:S/OTP-/erlang21-/}
PKGREVISION=		2
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GITHUB:=erlang/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.erlang.org/
COMMENT=		Concurrent functional programming language
LICENSE=		apache-2.0

EXTRACT_USING=		bsdtar
DIST_SUBDIR=		erlang

WRKSRC=			${WRKDIR}/otp-${DISTNAME}
GNU_CONFIGURE=		yes
USE_GNU_CONFIGURE_HOST=	${USE_CROSS_COMPILE}
OVERRIDE_DIRDEPTH=	4
USE_TOOLS+=		autoconf awk gmake perl:run flex

CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}

PTHREAD_OPTS+=		require native
CONFIGURE_ARGS+=	--enable-threads

# "This run-time was supposed be compiled with all code below 2Gb,
# but the instruction 'allocate_tt' is located at 00000001c586f34c."
MKPIE_SUPPORTED=	no

.include "../../mk/bsd.prefs.mk"

MAKE_ENV+=		DESTDIR=${DESTDIR}

do-configure-post-hook: replace-interpreter

REPLACE_INTERPRETER+=	escript
REPLACE.escript.old=	.*escript
REPLACE.escript.new=	${PREFIX}/lib/erlang21/bin/escript
REPLACE_FILES.escript=	\
	lib/diameter/bin/diameterc \
	lib/erl_docgen/priv/bin/codeline_preprocessing.escript \
	lib/erl_docgen/priv/bin/xml_from_edoc.escript \
	lib/reltool/examples/display_args \
	lib/reltool/examples/mnesia_core_dump_viewer \
	lib/snmp/src/compile/snmpc.src

SUBST_CLASSES+=		target
SUBST_STAGE.target=	pre-configure
SUBST_FILES.target=	make/target.mk
SUBST_SED.target=	-e "s|=.*config.guess)|= ${MACHINE_GNU_PLATFORM}|"
SUBST_MESSAGE.target=	Fixing target name.

TEST_TARGET=		tests
TEST_MAKE_FLAGS=	ERL_TOP=${WRKSRC}

SMF_NAME=		epmd21

CONFIGURE_ARGS.DragonFly+=	--disable-sctp

###
### XXX There may be others here.
###
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD" || ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--enable-kernel-poll
.endif

CHECK_RELRO_SKIP+=	lib/erlang21/lib/megaco-${VERSION.megaco}/priv/lib/megaco_flex_scanner_drv.so
CHECK_RELRO_SKIP+=	lib/erlang21/lib/megaco-${VERSION.megaco}/priv/lib/megaco_flex_scanner_drv_mt.so

.include "options.mk"

pre-configure:
	cd ${WRKSRC} && ./otp_build autoconf

###
### Ensure this gets rebuilt.
###
pre-build:
	${RUN} ${RM} -f ${WRKSRC}/lib/stdlib/ebin/dets_v9.beam

###
### Generate a list of module versions.
###
.PHONY: versions
versions: do-extract
	@${ECHO} "# \$$NetBSD\$$" > ${.CURDIR}/versions.mk
	@${ECHO} "# Do not edit, regenerate using 'make versions'" >> ${.CURDIR}/versions.mk
	@${ECHO} "_VERSIONS= \\" >> ${.CURDIR}/versions.mk
	${AWK} -F: '/OTP-${PKGVERSION_NOREV} :/{print $$2}' ${WRKSRC}/otp_versions.table |\
		${SED} -e 's/# //g' -e 's/-/ /g' >> ${.CURDIR}/versions.mk

post-install:
	chmod -R go-w ${DESTDIR}${PREFIX}/lib/erlang21/lib

.include "Makefile.versions"

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
