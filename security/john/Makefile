# $NetBSD: Makefile,v 1.21 2012/10/23 18:16:31 asau Exp $
#

DISTNAME=	john-1.7.6
PKGREVISION=	1
CATEGORIES=	security textproc
MASTER_SITES=	http://www.openwall.com/john/g/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openwall.com/john/
COMMENT=	Unix Password Cracker
LICENSE=	gnu-gpl-v2

NO_CONFIGURE=	yes
BUILD_DIRS=	src
TEST_TARGET=	check

.include "../../mk/compiler.mk"
.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" && ${MACHINE_ARCH} == "sparc"
.  if !empty(CC_VERSION:MSun)
.    if defined(SPARC_TARGET_ARCH) && ${SPARC_TARGET_ARCH} == "sparcv9"
BUILD_TARGET=	solaris-sparc-v9-cc
.    else
BUILD_TARGET=	solaris-sparc-v8-cc
.    endif
.  else
BUILD_TARGET=	solaris-sparc-gcc
.  endif
.elif ${OPSYS} == "SunOS" && ${MACHINE_ARCH} == "i386"
BUILD_TARGET=	solaris-x86-any
.elif ${OPSYS} == "NetBSD"
.  if ${MACHINE_ARCH} == "i386"
BUILD_TARGET=	openbsd-x86-any
.  elif ${MACHINE_ARCH} == "x86_64"
BUILD_TARGET=	openbsd-x86-64
.  elif ${MACHINE_ARCH} == "sparc64"
BUILD_TARGET=	netbsd-sparc64
.  elif ${MACHINE_ARCH} == "sparc"
BUILD_TARGET=	openbsd-sparc
.  elif ${MACHINE_ARCH} == "alpha"
BUILD_TARGET=	openbsd-alpha
.  elif ${MACHINE_ARCH} == "powerpc"
BUILD_TARGET=	openbsd-ppc32
.  elif ${MACHINE_ARCH} == "powerpc64"
BUILD_TARGET=	openbsd-ppc64
.  elif ${MACHINE_ARCH} == "vax"
BUILD_TARGET=	netbsd-vax
.  else
BUILD_TARGET=	generic
.  endif
.elif ${OPSYS} == "OpenBSD"
.  if ${MACHINE_ARCH} == "i386"
BUILD_TARGET=	openbsd-x86-any
.  elif ${MACHINE_ARCH} == "x86_64"
BUILD_TARGET=	openbsd-x86-64
.  elif ${MACHINE_ARCH} == "sparc64"
BUILD_TARGET=	openbsd-sparc64
.  elif ${MACHINE_ARCH} == "sparc"
BUILD_TARGET=	openbsd-sparc
.  elif ${MACHINE_ARCH} == "alpha"
BUILD_TARGET=	openbsd-alpha
.  elif ${MACHINE_ARCH} == "powerpc"
BUILD_TARGET=	openbsd-ppc32
.  elif ${MACHINE_ARCH} == "powerpc64"
BUILD_TARGET=	openbsd-ppc64
.  else
BUILD_TARGET=	generic
.  endif
.else
BUILD_TARGET=	generic
.endif

INSTALLATION_DIRS=	bin share/john

SUBST_CLASSES+=		john
SUBST_STAGE.john=	pre-build
SUBST_FILES.john=	src/params.h
SUBST_SED.john=		-e "s+@PREFIX@+${PREFIX}+g"

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
.for i in all.chr alnum.chr alpha.chr digits.chr lanman.chr password.lst
	${INSTALL_DATA} ${WRKSRC}/run/${i} ${DESTDIR}${PREFIX}/share/john
.endfor

.include "../../mk/bsd.pkg.mk"
