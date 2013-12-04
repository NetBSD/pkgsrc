# $NetBSD: Makefile,v 1.87 2013/12/04 21:02:23 richard Exp $

DISTNAME=	icu4c-52_1-src
PKGNAME=	${DISTNAME:S/4c//:S/-src//:S/_/./g}
CATEGORIES=	textproc
MASTER_SITES=	http://download.icu-project.org/files/icu4c/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.icu-project.org/
COMMENT=	Robust and full-featured Unicode services
LICENSE=	mit

WRKSRC=			${WRKDIR}/icu/source
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
TEST_TARGET=		check
UNLIMIT_RESOURCES+=	datasize
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-static
CONFIGURE_ENV+=		U_MAKE=${TOOLS_GMAKE}

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} != "native"
CONFIGURE_ARGS+=	--disable-threads
.endif

.include "../../mk/compiler.mk"

.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD" || ${OPSYS} == "DragonFly" || ${OPSYS} == "MirBSD"
PLIST_SUBST+=		MH_NAME=mh-bsd-gcc
.elif ${OPSYS} == "Linux"
PLIST_SUBST+=		MH_NAME=mh-linux
.elif ${OPSYS} == "SunOS"
.  if !empty(CC_VERSION:Mgcc*)
PLIST_SUBST+=		MH_NAME=mh-solaris-gcc
.  else
PLIST_SUBST+=		MH_NAME=mh-solaris
.  endif
.  if !empty(CC_VERSION:Mgcc-4.[6-9].*)
BUILDLINK_TRANSFORM+=	rm:-D__STDC__=0
.  endif
BUILDLINK_TRANSFORM+=	rm:-ansi
.elif ${OPSYS} == "IRIX"
PLIST_SUBST+=		MH_NAME=mh-irix
.elif ${OPSYS} == "Darwin"
PLIST_SUBST+=		MH_NAME=mh-darwin
.elif ${OPSYS} == "Cygwin"
PLIST_SUBST+=		MH_NAME=mh-cygwin
.else
# For unknown systems, set the filename to mh-unknown so that the user
# gets a warning about missing files.
PLIST_SUBST+=		MH_NAME=mh-unknown
.endif

.if ${OPSYS} == "Darwin" || ${OPSYS} == "Cygwin"
INSTALL_UNSTRIPPED=	yes
.endif

# expect builtin gcc atomic functions for gcc>=4.1
# (source/common/putilimp.h)
.if !empty(CC_VERSION:Mgcc-*) &&	\
	(empty(CC_VERSION:Mgcc-4.0*) && empty(CC_VERSION:Mgcc-[0-3].*))
.  if ${MACHINE_ARCH} == "i386"
CFLAGS+=	-march=i486
.  endif
.endif

INSTALLATION_DIRS=	bin

.if ${OPSYS} == "Cygwin"
post-install:
	mv ${DESTDIR}${PREFIX}/lib/cygicudata.dll ${DESTDIR}${PREFIX}/bin/
.endif

.include "../../mk/bsd.pkg.mk"
