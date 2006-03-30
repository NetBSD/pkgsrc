# $NetBSD: Makefile,v 1.14 2006/03/30 13:38:41 salo Exp $
#

DISTNAME=	john-1.7.0.2
#PKGREVISION=	1
CATEGORIES=	security textproc
MASTER_SITES=	http://www.openwall.com/john/f/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	DawS@irc.pl
HOMEPAGE=	http://www.openwall.com/john/
COMMENT=	Unix Password Cracker

NO_CONFIGURE=	yes
BUILD_DIRS=	src

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
.else
BUILD_TARGET=	generic
.endif

INSTALLATION_DIRS=	bin

SUBST_CLASSES+=		john
SUBST_STAGE.john=	pre-build
SUBST_FILES.john=	src/params.h
SUBST_SED.john=		-e "s+@PREFIX@+${PREFIX}+g"

do-install:
	# programs and scripts
	${INSTALL_PROGRAM} ${WRKSRC:Q}/run/john ${PREFIX:Q}/bin
	${INSTALL_SCRIPT} ${WRKSRC:Q}/run/mailer ${PREFIX:Q}/bin

	# data directory
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/john

	# configuration file
	${INSTALL_DATA} ${WRKSRC:Q}/run/john.conf ${PREFIX:Q}/share/john

	# symbolic links
.for i in unafs unique unshadow
	${LN} -sf ${PREFIX:Q}/bin/john ${PREFIX:Q}/bin/${i:Q}
.endfor

	# data files
.for i in all.chr alnum.chr alpha.chr digits.chr lanman.chr password.lst
	${INSTALL_DATA} ${WRKSRC:Q}/run/${i:Q} ${PREFIX:Q}/share/john
.endfor

.include "../../mk/bsd.pkg.mk"
