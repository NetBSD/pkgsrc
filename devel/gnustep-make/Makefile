# $NetBSD: Makefile,v 1.60 2020/04/16 09:21:51 manu Exp $

DISTNAME=	gnustep-make-2.8.0
#PKGREVISION=	1
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=core/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	GNUstep makefile package
LICENSE=	gnu-gpl-v3

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

CONF_FILES+=		${PREFIX}/share/examples/GNUstep/GNUstep-strict-v2.conf\
			${PKG_SYSCONFDIR}/GNUstep.conf

REPLACE_BASH+=		bake_debian_files.sh

.include "gnustep.mk"
.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "pth")
PTHREAD_LIBS+=		-lpth
.endif

CONFIGURE_ARGS+=	--with-thread-lib=${PTHREAD_LIBS:Q}

.if ${MACHINE_ARCH} == "i386"
GNUSTEP_ARCH=	ix86
.else
GNUSTEP_ARCH=	${MACHINE_ARCH}
.endif
PLIST_SUBST+=	GNUSTEP_ARCH=${GNUSTEP_ARCH}

SUBST_CLASSES+=		target
SUBST_STAGE.target=	pre-configure
SUBST_FILES.target=	target.make
SUBST_SED.target+=	-e 's|/usr/pkg|${PREFIX}|g'

SUBST_CLASSES+=		maninfo
SUBST_STAGE.maninfo=	pre-configure
SUBST_MESSAGE.maninfo=	Fixing man directory references.
SUBST_FILES.maninfo=	${WRKSRC}/FilesystemLayouts/fhs
SUBST_SED.maninfo=	-e 's|share/man|${PKGMANDIR}|'
SUBST_SED.maninfo+=	-e 's|share/info|${PKGINFODIR}|'

SUBST_CLASSES+=			unwrapping
SUBST_STAGE.unwrapping=		post-build
SUBST_MESSAGE.unwrapping=	Unwrapping wrapper scripts.
SUBST_FILES.unwrapping=		TestFramework/gnustep-tests
SUBST_SED.unwrapping=		-e 's|${TOOLS_DIR}|${PREFIX}|g'

INSTALLATION_DIRS+=	share/GNUstep/Library
INSTALLATION_DIRS+=	share/GNUstep/Makefiles/${GNUSTEP_ARCH}
INSTALLATION_DIRS+=	share/GNUstep/Makefiles/Additional
INSTALLATION_DIRS+=	share/GNUstep/Makefiles/Auxiliary

.include "../../mk/bsd.pkg.mk"
