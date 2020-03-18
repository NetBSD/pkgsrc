# $NetBSD: Makefile,v 1.129 2020/03/18 00:26:28 rillig Exp $

DISTNAME=	icu4c-64_2-src
PKGNAME=	${DISTNAME:S/4c//:S/-src//:S/_/./g}
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://download.icu-project.org/files/icu4c/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.icu-project.org/
COMMENT=	Robust and full-featured Unicode services
LICENSE=	mit

WRKSRC=			${WRKDIR}/icu/source
USE_LANGUAGES=		c99 c++
USE_TOOLS+=		gmake
GCC_REQD+=		4.8
TEST_TARGET=		check
UNLIMIT_RESOURCES+=	datasize
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-static
CONFIGURE_ENV+=		U_MAKE=${TOOLS_GMAKE}

CHECK_SSP_SKIP=		lib/libicudata.so*

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} != "native"
CONFIGURE_ARGS+=	--disable-threads
.endif

.include "../../mk/compiler.mk"

# from ICU_CHECK_MH_FRAG in source/acinclude.m4
.if ${OPSYS} == "SunOS"
.  if ${PKGSRC_COMPILER:Mclang} || ${PKGSRC_COMPILER:Mgcc}
PLIST_SUBST+=		MH_NAME=mh-solaris-gcc
.  else
PLIST_SUBST+=		MH_NAME=mh-solaris
.  endif
.  if !empty(CC_VERSION:Mgcc-4.[6-9].*)
BUILDLINK_TRANSFORM+=	rm:-D__STDC__=0
.  endif
BUILDLINK_TRANSFORM+=	rm:-ansi
.elif !empty(MACHINE_PLATFORM:MLinux-*-alpha)
.  if !empty(CC_VERSION:Mgcc*)
PLIST_SUBST+=		MH_NAME=mh-alpha-linux-gcc
.  else
PLIST_SUBST+=		MH_NAME=mh-alpha-linux-cc
.  endif
.elif !empty(MACHINE_PLATFORM:MLinux-*-powerpc*)
.  if !empty(CC_VERSION:Mgcc*)
PLIST_SUBST+=		MH_NAME=mh-linux
.  else
PLIST_SUBST+=		MH_NAME=mh-linux-va
.  endif
.elif ${OPSYS} == "Linux" || ${OPSYS} == "GNUkFreeBSD"
PLIST_SUBST+=		MH_NAME=mh-linux
.elif ${OPSYS} == "Cygwin"
PLIST_SUBST+=		MH_NAME=mh-cygwin
.elif !empty(OPSYS:M*BSD*) || ${OPSYS} == "DragonFly" || ${OPSYS} == "Bitrig"
PLIST_SUBST+=		MH_NAME=mh-bsd-gcc
.elif ${OPSYS} == "AIX"
.  if !empty(CC_VERSION:Mgcc*)
PLIST_SUBST+=		MH_NAME=mh-aix-gcc
.  else
PLIST_SUBST+=		MH_NAME=mh-aix-va
.  endif
.elif ${OPSYS} == "HPUX"
.  if !empty(CC_VERSION:Mgcc*)
PLIST_SUBST+=		MH_NAME=mh-hpux-gcc
.  else
PLIST_SUBST+=		MH_NAME=mh-hpux-acc
.  endif
.elif ${OPSYS} == "Darwin"
PLIST_SUBST+=		MH_NAME=mh-darwin
.elif ${OPSYS} == "Haiku"
PLIST_SUBST+=		MH_NAME=mh-haiku
.elif ${OPSYS} == "IRIX"
PLIST_SUBST+=		MH_NAME=mh-irix
.elif ${OPSYS} == "Cygwin"
PLIST_SUBST+=		MH_NAME=mh-cygwin
.elif ${OS_VARIANT} == "SCOOSR5"
PLIST_SUBST+=		MH_NAME=mh-scoosr5
.elif ${OPSYS} == "OSF1"
PLIST_SUBST+=		MH_NAME=mh-alpha-osf
.elif ${OPSYS} == "QNX"
PLIST_SUBST+=		MH_NAME=mh-qnx
.else
# For unknown systems, set the filename to mh-unknown so that the user
# gets a warning about missing files.
PLIST_SUBST+=		MH_NAME=mh-unknown
.endif

PKGCONFIG_OVERRIDE+=		config/icu*.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build

# work around ICU-20533 (build failure on big endian machines)
post-configure:
	${MKDIR} ${WRKSRC}/data/out

# expect builtin gcc atomic functions for gcc>=4.1
# (source/common/putilimp.h)
.if !empty(CC_VERSION:Mgcc-*) &&	\
	(empty(CC_VERSION:Mgcc-4.0*) && empty(CC_VERSION:Mgcc-[0-3].*))
.  if ${MACHINE_ARCH} == "i386"
CFLAGS+=	-march=i486
.  endif
.endif

.if ${OPSYS} == "Cygwin"
INSTALL_UNSTRIPPED=	yes
SO_MAJOR=		${PKGVERSION_NOREV:R}
.  for l in data i18n io le lx test tu uc
GENERATE_PLIST+=	${ECHO} bin/cygicu${l}${SO_MAJOR}.dll;
GENERATE_PLIST+=	${ECHO} lib/libicu${l}${SO_MAJOR}.dll.a;
.  endfor

post-install:
	mv ${DESTDIR}${PREFIX}/lib/cygicu*.dll ${DESTDIR}${PREFIX}/bin/
.  for l in data i18n io le lx test tu uc
	${LN} -s libicu${l}${SO_MAJOR}.dll.a ${DESTDIR}${PREFIX}/lib/libicu${l}.dll.a
.  endfor

SUBST_CLASSES+=		icu-config
SUBST_STAGE.icu-config=	post-install
SUBST_FILES.icu-config=	${DESTDIR}${PREFIX}/bin/icu-config
SUBST_SED.icu-config+=	-e '/^ICUUC_FILE=/ s/libdir/bindir/'
SUBST_SED.icu-config+=	-e 's/l$${LIBICU}/l$${ICUPREFIX}/g'
SUBST_SED.icu-config+=	-e '/l$${ICUPREFIX}/ s/$${ICULIBSUFFIX_VERSION}//g'
.endif

.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
