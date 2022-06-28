# $NetBSD: Makefile,v 1.8 2022/06/28 11:31:14 wiz Exp $

DISTNAME=	gdb-7.10
PKGNAME=	cross-arm-none-eabi-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GNU:=gdb/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Cross GDB for bare metal ARM EABI
LICENSE=	gnu-gpl-v3

ARMELF_PREFIX=	${PREFIX}/cross-arm-none-eabi

USE_TOOLS+=	gmake makeinfo
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

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		charsetalias
# this theoretically should match check for
# install-exec-localcharset in ${WRKSRC}/gdb/gnulib/import/Makefile.am
.if ${OPSYS} != Darwin
PLIST.charsetalias=	yes
.endif

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

post-install:
	${RM} ${DESTDIR}${PREFIX}/cross-arm-none-eabi/info/bfd.info

.include "../../mk/bsd.pkg.mk"
