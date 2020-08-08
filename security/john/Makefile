# $NetBSD: Makefile,v 1.31 2020/08/08 12:48:56 leot Exp $
#

DISTNAME=	john-1.9.0
PKGREVISION=	1
CATEGORIES=	security textproc
MASTER_SITES=	http://www.openwall.com/john/k/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.openwall.com/john/
COMMENT=	Unix Password Cracker
LICENSE=	gnu-gpl-v2

BUILD_DIRS=	src
TEST_TARGET=	check

.include "../../mk/compiler.mk"
.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
JOHN_ARCH.i386=		x86-any
JOHN_ARCH.sparc=	sparc
JOHN_ARCH.sparc64=	sparcv9
JOHN_ARCH.x86_64=	x86-64
JOHN_CC.gcc=		gcc
JOHN_CC.sunpro=		cc
BUILD_TARGET=		solaris-${JOHN_ARCH.${MACHINE_ARCH}}-${JOHN_CC.${PKGSRC_COMPILER}}
.elif ${OPSYS} == "NetBSD"
.  if ${MACHINE_ARCH} == "i386"
BUILD_TARGET=		openbsd-x86-any
.  elif ${MACHINE_ARCH} == "x86_64"
BUILD_TARGET=		openbsd-x86-64
.  elif ${MACHINE_ARCH} == "sparc64"
BUILD_TARGET=		netbsd-sparc64
.  elif ${MACHINE_ARCH} == "sparc"
BUILD_TARGET=		openbsd-sparc
.  elif ${MACHINE_ARCH} == "alpha"
BUILD_TARGET=		openbsd-alpha
.  elif ${MACHINE_ARCH} == "powerpc"
BUILD_TARGET=		openbsd-ppc32
.  elif ${MACHINE_ARCH} == "powerpc64"
BUILD_TARGET=		openbsd-ppc64
.  elif ${MACHINE_ARCH} == "vax"
BUILD_TARGET=		netbsd-vax
.  else
BUILD_TARGET=		generic
.  endif
.elif ${OPSYS} == "OpenBSD"
.  if ${MACHINE_ARCH} == "i386"
BUILD_TARGET=		openbsd-x86-any
.  elif ${MACHINE_ARCH} == "x86_64"
BUILD_TARGET=		openbsd-x86-64
.  elif ${MACHINE_ARCH} == "sparc64"
BUILD_TARGET=		openbsd-sparc64
.  elif ${MACHINE_ARCH} == "sparc"
BUILD_TARGET=		openbsd-sparc
.  elif ${MACHINE_ARCH} == "alpha"
BUILD_TARGET=		openbsd-alpha
.  elif ${MACHINE_ARCH} == "powerpc"
BUILD_TARGET=		openbsd-ppc32
.  elif ${MACHINE_ARCH} == "powerpc64"
BUILD_TARGET=		openbsd-ppc64
.  else
BUILD_TARGET=		generic
.  endif
.else
BUILD_TARGET=		generic
.endif

# Avoid possible per-platform optimization
MAKE_FLAGS+=	OPT_NORMAL=
MAKE_FLAGS+=	OPT_INLINE=

INSTALLATION_DIRS=	bin share/john share/doc/john

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing hardcoded paths.
SUBST_FILES.fix-paths=		src/params.h
SUBST_VARS.fix-paths=		PREFIX

do-install:
	# programs and scripts
	${INSTALL_PROGRAM} ${WRKSRC}/run/john ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/run/mailer ${DESTDIR}${PREFIX}/bin
	# configuration file
	${INSTALL_DATA} ${WRKSRC}/run/john.conf ${DESTDIR}${PREFIX}/share/john
	# symbolic links
.for i in unafs unique unshadow
	${LN} -sf john ${DESTDIR}${PREFIX}/bin/${i}
.endfor
	# data files
.for i in alnum.chr alpha.chr ascii.chr digits.chr lm_ascii.chr lower.chr \
    lowernum.chr lowerspace.chr upper.chr uppernum.chr password.lst
	${INSTALL_DATA} ${WRKSRC}/run/${i} ${DESTDIR}${PREFIX}/share/john
.endfor
	# documentation
.for i in CONFIG EXAMPLES FAQ MODES OPTIONS README RULES
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DESTDIR}${PREFIX}/share/doc/john
.endfor

.include "../../mk/bsd.pkg.mk"
