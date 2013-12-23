# $NetBSD: Makefile,v 1.55 2013/12/23 11:57:03 wiz Exp $

DISTNAME=	gnustep-make-2.6.2
PKGREVISION=	1
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=core/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	GNUstep makefile package
LICENSE=	gnu-gpl-v3

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES+=		c99 objc c++ obj-c++
USE_TOOLS+=		csh
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		INSTALL_PROGRAM=${INSTALL_SCRIPT:Q}
CONFIGURE_ARGS+=	--disable-importing-config-file
CONFIGURE_ARGS+=	--with-layout=fhs
CONFIGURE_ARGS+=	--enable-native-objc-exceptions
CONFIGURE_ARGS+=	--with-config-file=${PKG_SYSCONFDIR}/GNUstep.conf
CONFIGURE_ARGS+=	--with-objc-lib-flag="-L${PREFIX}/lib -Wl,-R${PREFIX}/lib -lobjc"
MAKE_FILE=		GNUmakefile

CONF_FILES+=		${PREFIX}/share/examples/GNUstep/GNUstep.conf \
			${PKG_SYSCONFDIR}/GNUstep.conf

.include "gnustep.mk"
.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "pth")
PTHREAD_LIBS+=		-lpth
.endif

CONFIGURE_ARGS+=	--with-thread-lib=${PTHREAD_LIBS:Q}
.if empty(PKG_OPTIONS:Mfragile)
CONFIGURE_ARGS+=	--enable-objc-nonfragile-abi
.endif

.if ${MACHINE_ARCH} == "i386"
GNUSTEP_ARCH=	ix86
.else
GNUSTEP_ARCH=	${MACHINE_ARCH}
.endif
PLIST_SUBST+=	GNUSTEP_ARCH=${GNUSTEP_ARCH}

SUBST_CLASSES+=		target
SUBST_STAGE.target=	post-patch
SUBST_FILES.target=	target.make
SUBST_SED.target+=	-e 's|/usr/pkg|${PREFIX}|g'

SUBST_CLASSES+=		maninfo
SUBST_STAGE.maninfo=	pre-configure
SUBST_MESSAGE.maninfo=	Fixing man directory references.
SUBST_FILES.maninfo=	${WRKSRC}/FilesystemLayouts/fhs
SUBST_SED.maninfo=	-e 's|share/man|${PKGMANDIR}|'
SUBST_SED.maninfo+=	-e 's|share/info|${PKGINFODIR}|'

SUBST_CLASSES+=         unwrapping
SUBST_STAGE.unwrapping= post-build
SUBST_MESSAGE.unwrapping=Unwrapping wrapper scripts.
SUBST_FILES.unwrapping= TestFramework/gnustep-tests
SUBST_SED.unwrapping=   -e 's|${TOOLS_DIR}|${PREFIX}|g'

INSTALLATION_DIRS+=	share/GNUstep/Library
INSTALLATION_DIRS+=	share/GNUstep/Makefiles/${GNUSTEP_ARCH}
INSTALLATION_DIRS+=	share/GNUstep/Makefiles/Additional
INSTALLATION_DIRS+=	share/GNUstep/Makefiles/Auxiliary

.include "../../mk/bsd.pkg.mk"
