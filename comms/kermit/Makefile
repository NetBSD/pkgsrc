# $NetBSD: Makefile,v 1.78 2011/11/20 12:01:50 tron Exp $

DISTNAME=	cku302
PKGNAME=	kermit-9.0.302
CATEGORIES=	comms
MASTER_SITES=	ftp://kermit.columbia.edu/kermit/archives/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.columbia.edu/kermit/
COMMENT=	Network and serial communication, file transfer, and scripting utility
LICENSE=	kermit-license

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	${PKGNAME_NOREV}
BUILD_DEFS+=	KFLAGS LIBS MANINSTALL
MAKE_ENV+=	KFLAGS=${KFLAGS:Q} LIBS=${LIBS:Q}
MAKE_FILE=	makefile

#KFLAGS+=	-DNODEBUG -DNOOLDMODEMS

.include "options.mk"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/kermit

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wermit ${DESTDIR}${PREFIX}/bin/kermit
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DESTDIR}${PREFIX}/share/doc/kermit
	${INSTALL_MAN} ${WRKSRC}/ckuker.nr \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/kermit.1; \

.for p in NetBSD-1.3*
.  if ${MACHINE_PLATFORM:M${p}} != ""
LIBS+=		-ltermcap
.  endif
.endfor

.if ${OPSYS} == "Darwin"
.  if !empty(OS_VERSION:M??.*)
BUILD_TARGET_OPSYS=	macosx10.6
.  elif !empty(OS_VERSION:M9.*)
BUILD_TARGET_OPSYS=	macosx10.5
.  elif !empty(OS_VERSION:M8.*)
BUILD_TARGET_OPSYS=	macosx10.4
.  elif empty(OS_VERSION:M7.*)
BUILD_TARGET_OPSYS=	macosx103.9
.  else
BUILD_TARGET_OPSYS=	macosx10
.  endif
.elif ${OPSYS} == "Linux"
BUILD_TARGET_OPSYS=	linux
.elif ${OPSYS} == "SunOS"
BUILD_TARGET_OPSYS=	solaris11g
.else
BUILD_TARGET_OPSYS=	netbsd
.endif

BUILD_TARGET=	${BUILD_TARGET_OPSYS}${BUILD_TARGET_OPTIONS:ts}

.include "../../mk/bsd.pkg.mk"
