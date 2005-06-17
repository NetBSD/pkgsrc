# $NetBSD: Makefile,v 1.10 2005/06/17 03:50:32 jlam Exp $
#

DISTNAME=	john-1.6
PKGREVISION=	1
CATEGORIES=	security textproc
MASTER_SITES=	http://www.openwall.com/john/

MAINTAINER=	DawS@irc.pl
HOMEPAGE=	http://www.openwall.com/john/
COMMENT=	Unix Password Cracker

WRKSRC=		${WRKDIR}/${DISTNAME}/src

NO_CONFIGURE=	# defined

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

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../run/john ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/john
	${INSTALL_DATA} ${WRKSRC}/../run/all.chr ${PREFIX}/share/john
	${INSTALL_DATA} ${WRKSRC}/../run/alpha.chr ${PREFIX}/share/john
	${INSTALL_DATA} ${WRKSRC}/../run/digits.chr ${PREFIX}/share/john
	${INSTALL_DATA} ${WRKSRC}/../run/john.ini ${PREFIX}/share/john
	${INSTALL_DATA} ${WRKSRC}/../run/mailer ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/../run/password.lst ${PREFIX}/share/john
	${LN} -sf ${PREFIX}/bin/john ${PREFIX}/bin/unafs
	${LN} -sf ${PREFIX}/bin/john ${PREFIX}/bin/unique
	${LN} -sf ${PREFIX}/bin/john ${PREFIX}/bin/unshadow

.include "../../mk/bsd.pkg.mk"
