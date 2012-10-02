# $NetBSD: Makefile,v 1.65 2012/10/02 20:11:47 asau Exp $
#

VERSION=		4.7.0
RTYPE=			devel
DISTNAME=		parrot-${VERSION}
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.parrot.org/pub/parrot/releases/${RTYPE}/${VERSION}/

MAINTAINER=		he@NetBSD.org
HOMEPAGE=		http://www.parrotcode.org/
COMMENT=		Virtual machine made to run Perl 6 and other languages
LICENSE=		artistic-2.0

USE_LANGUAGES=		c c++
USE_TOOLS+=		perl
PTHREAD_OPTS+=		require
BUILD_TARGET=		world
TEST_TARGET=		test
HAS_CONFIGURE=		yes

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.prefs.mk"

CONFIG_SHELL=		perl
CONFIGURE_SCRIPT=	Configure.pl
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q} \
			--icu-config=${PREFIX}/bin/icu-config \
			--optimize

SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	post-configure
SUBST_FILES.pthread=	Makefile
SUBST_SED.pthread=	-e 's|-pthread||g'
SUBST_SED.pthread+=	-e 's|-lpthread||g'
SUBST_SED.pthread+=	-e 's|-lc_r||g'
SUBST_SED.pthread+=	-e '/^CFLAGS /s|$$|${PTHREAD_CFLAGS:Q}|'
SUBST_SED.pthread+=	-e '/^LINKFLAGS /s|$$|${PTHREAD_LDFLAGS:Q} ${PTHREAD_LIBS:Q}|'
SUBST_SED.pthread+=	-e '/^LDFLAGS /s|$$|${PTHREAD_LDFLAGS:Q} ${PTHREAD_LIBS:Q}|'

PLIST_SUBST+=		VERSION=${VERSION:Q}
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
REPLACE_FILES.parrot+= 	tools/dev/pbc_to_exe.pir

REPLACE_INTERPRETER+=	parrot-nqp
REPLACE.parrot-nqp.old=	.*parrot-nqp[^[:space:]]*
REPLACE.parrot-nqp.new= ${PREFIX}/bin/parrot-nqp
REPLACE_FILES.parrot-nqp+= compilers/data_json/JSON.nqp

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
CHECK_WRKREF_SKIP+=	lib/parrot/${VERSION}/include/config.fpmc
CHECK_WRKREF_SKIP+=	lib/parrot/${VERSION}/parrot_config.o
CHECK_WRKREF_SKIP+=	lib/parrot/${VERSION}/tools/lib/Parrot/Config/Generated.pm

# Does relink internally, so allow local rpath entries
BUILDLINK_PASSTHRU_RPATHDIRS+=	${WRKSRC}

pre-install:
	${CHMOD} -R g-w ${WRKSRC}

.include "../../textproc/icu/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
