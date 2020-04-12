# $NetBSD: Makefile,v 1.97 2020/04/12 08:27:58 adam Exp $
#

DISTNAME=		parrot-${PARROT_VERSION}
PKGREVISION=		21
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.parrot.org/pub/parrot/releases/${PARROT_RTYPE}/${PARROT_VERSION}/

MAINTAINER=		he@NetBSD.org
HOMEPAGE=		http://www.parrotcode.org/
COMMENT=		Virtual machine made to run Perl 6 and other languages
LICENSE=		artistic-2.0

USE_LANGUAGES=		c c++
USE_TOOLS+=		perl gmake
PTHREAD_OPTS+=		require
BUILD_TARGET=		world
TEST_TARGET=		test
HAS_CONFIGURE=		yes
MAKE_JOBS_SAFE=		no

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.prefs.mk"

CONFIG_SHELL=		perl
CONFIGURE_SCRIPT=	Configure.pl
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q} \
			--mandir=${PREFIX:Q}/${PKGMANDIR:Q} \
			--icu-config=${PREFIX}/bin/icu-config \
			--without-opengl --without-pcre \
			--without-zlib \
			--without-libffi \
			--optimize
# --without-llvm

SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	post-configure
SUBST_FILES.pthread=	Makefile
SUBST_SED.pthread=	-e 's|-pthread||g'
SUBST_SED.pthread+=	-e 's|-lpthread||g'
SUBST_SED.pthread+=	-e 's|-lc_r||g'
SUBST_SED.pthread+=	-e '/^CFLAGS /s|$$|${PTHREAD_CFLAGS:Q}|'
SUBST_SED.pthread+=	-e '/^LINKFLAGS /s|$$|${PTHREAD_LDFLAGS:Q} ${PTHREAD_LIBS:Q}|'
SUBST_SED.pthread+=	-e '/^LDFLAGS /s|$$|${PTHREAD_LDFLAGS:Q} ${PTHREAD_LIBS:Q}|'

PLIST_SUBST+=		PARROT_VERSION=${PARROT_VERSION:Q}
PRINT_PLIST_AWK+=	{ gsub(/${PARROT_VERSION}/, "$${PARROT_VERSION}") }
PLIST_SRC+=		${PLIST_SRC_DFLT}
# Default this to ELF shared libs with .so,
# Darwin has PLIST.Darwin which gets included automatically.
.if (${OPSYS} != "Darwin")
PLIST_SRC+=		PLIST.shared
.endif

REPLACE_PERL+=		tools/build/ops2c.pl
REPLACE_PERL+=		tools/build/pmc2c.pl
REPLACE_PERL+=		tools/dev/create_language.pl
REPLACE_PERL+=		tools/dev/gen_makefile.pl
REPLACE_PERL+=		tools/dev/mk_language_shell.in
REPLACE_PERL+=		tools/dev/pprof2cg.pl
REPLACE_PERL+=		tools/dev/reconfigure.pl

REPLACE_INTERPRETER+=	parrot
REPLACE.parrot.old=	.*parrot[^[:space:]]*
REPLACE.parrot.new=	${PREFIX}/bin/parrot
REPLACE_FILES.parrot+=	tools/dev/pbc_to_exe.pir

REPLACE_INTERPRETER+=		parrot-nqp
REPLACE.parrot-nqp.old=		.*parrot-nqp[^[:space:]]*
REPLACE.parrot-nqp.new=		${PREFIX}/bin/parrot-nqp
REPLACE_FILES.parrot-nqp+=	compilers/data_json/JSON.nqp

REPLACE_INTERPRETER+=	nqp
REPLACE.nqp.old=	.*nqp[^[:space:]]*
REPLACE.nqp.new=	${PREFIX}/bin/parrot-nqp
REPLACE_FILES.nqp+=	runtime/parrot/library/YAML/Tiny.pm

# These have been reported to parrot, Git tracking issue #201
CHECK_WRKREF_SKIP+=	bin/ops2c
CHECK_WRKREF_SKIP+=	bin/parrot
CHECK_WRKREF_SKIP+=	bin/parrot-nqp
CHECK_WRKREF_SKIP+=	bin/parrot-prove
CHECK_WRKREF_SKIP+=	bin/parrot_config
CHECK_WRKREF_SKIP+=	bin/parrot_nci_thunk_gen
CHECK_WRKREF_SKIP+=	bin/pbc_merge
CHECK_WRKREF_SKIP+=	bin/pbc_to_exe
CHECK_WRKREF_SKIP+=	bin/winxed
CHECK_WRKREF_SKIP+=	lib/parrot/${PARROT_VERSION}/include/config.fpmc
CHECK_WRKREF_SKIP+=	lib/parrot/${PARROT_VERSION}/parrot_config.o
CHECK_WRKREF_SKIP+=	lib/parrot/${PARROT_VERSION}/tools/lib/Parrot/Config/Generated.pm
CHECK_WRKREF_SKIP+=	src/parrot/${PARROT_VERSION}/config_lib.pir

# Does relink internally, so allow local rpath entries
BUILDLINK_PASSTHRU_RPATHDIRS+=	${WRKSRC}

pre-install:
	${CHMOD} -R g-w ${WRKSRC}

.include "../../lang/parrot/version.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
