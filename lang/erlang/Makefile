# $NetBSD: Makefile,v 1.121 2024/03/17 18:35:50 nia Exp $

DISTNAME=	erlang-${DIST_VERSION_MAJOR}.${DIST_VERSION_MINOR}${!empty(DIST_VERSION_PATCH):?.:}${DIST_VERSION_PATCH}
PKGNAME=	${DISTNAME:S/OTP-/erlang-/}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=erlang/}
GITHUB_PROJECT=	otp
GITHUB_TAG=	OTP-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.erlang.org/
COMMENT=	Concurrent functional programming language
LICENSE=	apache-2.0

EXTRACT_USING=	bsdtar

WRKSRC=		${WRKDIR}/otp-${GITHUB_TAG}
GNU_CONFIGURE=	yes
USE_TOOLS+=	awk gmake perl:run flex
USE_LANGUAGES+=	c c++

# "This run-time was supposed be compiled with all code below 2Gb,
# but the instruction 'allocate_tt' is located at 00000001c586f34c."
MKPIE_SUPPORTED=	no

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH:M*armv6*} || ${MACHINE_ARCH:M*armv7*}
MAKE_FLAGS+=	ARCH=arm
.endif

.if ${USE_CROSS_COMPILE:U:tl} == yes
USE_GNU_CONFIGURE_HOST=	yes
.else
USE_GNU_CONFIGURE_HOST=	no
.endif
OVERRIDE_DIRDEPTH=	4

CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}

PTHREAD_OPTS+=		require native
CONFIGURE_ARGS+=	--enable-threads

MAKE_ENV+=		DESTDIR=${DESTDIR}

REPLACE_INTERPRETER+=	escript
REPLACE.escript.old=	.*escript
REPLACE.escript.new=	${PREFIX}/bin/escript
REPLACE_FILES.escript+=	lib/diameter/bin/diameterc
REPLACE_FILES.escript+=	lib/edoc/bin/edoc
REPLACE_FILES.escript+=	lib/erl_docgen/priv/bin/codeline_preprocessing.escript
REPLACE_FILES.escript+=	lib/erl_docgen/priv/bin/xml_from_edoc.escript
REPLACE_FILES.escript+=	lib/snmp/src/compile/snmpc.src

SUBST_CLASSES+=		target
SUBST_STAGE.target=	pre-configure
SUBST_FILES.target=	make/target.mk
SUBST_SED.target=	-e "s|=.*config.guess)|= ${MACHINE_GNU_PLATFORM}|"
SUBST_MESSAGE.target=	Fixing target name.

TEST_TARGET=		tests
TEST_MAKE_FLAGS=	ERL_TOP=${WRKSRC}

SMF_NAME=		epmd

CONFIGURE_ARGS.DragonFly+=	--disable-sctp

.if defined(OPSYS_HAS_KQUEUE) && ${OPSYS} != "Darwin"
CONFIGURE_ARGS+=	--enable-kernel-poll
.endif

# Erlang rejects kqueue implementations before Sierra.
.if ${OPSYS} == "Darwin" && ${OPSYS_VERSION} > 101200
CONFIGURE_ARGS+=	--enable-kernel-poll
.endif

CHECK_RELRO_SKIP+=	lib/erlang/lib/megaco-${VERSION.megaco}/priv/lib/megaco_flex_scanner_drv.so
CHECK_RELRO_SKIP+=	lib/erlang/lib/megaco-${VERSION.megaco}/priv/lib/megaco_flex_scanner_drv_mt.so

.include "options.mk"

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
	${AWK} -F: '/OTP-${PKGVERSION_NOREV} :/{print $$2}' ${WRKSRC}/otp_versions.table | \
		${SED} -e 's/# //g' -e 's/-/ /g' \
		       -e 's,^ ,_VERSIONS=	,' \
		       -e 's, *$$,,' \
			>> ${.CURDIR}/versions.mk

post-install:
	chmod -R go-w ${DESTDIR}${PREFIX}/lib/erlang/lib

.include "Makefile.versions"

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
