# $NetBSD: Makefile,v 1.29 2010/02/23 12:41:14 he Exp $
#

VERSION=		2.1.1
RTYPE=			devel
DISTNAME=		parrot-${VERSION}
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.parrot.org/pub/parrot/releases/${RTYPE}/${VERSION}/

MAINTAINER=		he@NetBSD.org
HOMEPAGE=		http://www.parrotcode.org/
COMMENT=		Virtual machine made to run Perl 6 and other languages
LICENSE=		artistic-2.0

PKG_DESTDIR_SUPPORT=	user-destdir
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
			--icu-config=${PREFIX}/bin/icu-config

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
REPLACE_PERL+=		tools/dev/gen_makefile.pl
REPLACE_PERL+=		tools/dev/mk_language_shell.pl
REPLACE_PERL+=		tools/dev/reconfigure.pl
REPLACE_PERL+=		lib/Parrot/Op.pm
#REPLACE_PERL+=		lib/Parrot/OpLib/core.pm
REPLACE_PERL+=		lib/Parrot/OpTrans/CPrederef.pm
REPLACE_PERL+=		lib/Parrot/OpsFile.pm


REPLACE_INTERPRETER+=	parrot
REPLACE.parrot.old=	.*parrot[^[:space:]]*
REPLACE.parrot.new=	${PREFIX}/bin/parrot
REPLACE_FILES.parrot+= 	tools/dev/pbc_to_exe.pir


pre-install:
	${CHMOD} -R g-w ${WRKSRC}

.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
