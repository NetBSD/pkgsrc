# $NetBSD: Makefile,v 1.10 2025/09/09 01:53:45 lloyd Exp $

DISTNAME=	gdb-16.3
PKGNAME=	cross-arm-none-eabi-${DISTNAME}
#PKGREVISION=	3
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GNU:=gdb/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Cross GDB for bare metal ARM EABI
LICENSE=	gnu-gpl-v3

ARMELF_PREFIX=	${PREFIX}/cross-arm-none-eabi

USE_TOOLS+=	gmake makeinfo
USE_LANGUAGES=	c c++
TOOLS_BROKEN+=	perl # used in do-install for texi2pod
GNU_CONFIGURE=	yes

OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure
GNU_CONFIGURE_PREFIX=	${ARMELF_PREFIX}

CONFIGURE_ARGS+=	--disable-werror --target=arm-none-eabi
CONFIGURE_ARGS+=	--disable-nls
INFO_FILES=		yes

# Uses all kinds of bashisms but is only needed for testing.
# If ever necessary, this should be fixed using REPLACE_BASH.
CHECK_PORTABILITY_SKIP+=	sim/testsuite/sim/bfin/run-tests.sh

.include "options.mk"
.include "../../mk/bsd.prefs.mk"

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

post-install:
	${RM} ${DESTDIR}${PREFIX}/cross-arm-none-eabi/info/bfd.info
	${RM} ${DESTDIR}${PREFIX}/cross-arm-none-eabi/info/ctf-spec.info
	${RM} ${DESTDIR}${PREFIX}/cross-arm-none-eabi/info/sframe-spec.info

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
