# $NetBSD: Makefile,v 1.24 2009/12/09 09:23:50 he Exp $
#

VERSION=		1.7.0
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


pre-install:
	${CHMOD} -R g-w ${WRKSRC}

.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
