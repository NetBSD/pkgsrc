# $NetBSD: Makefile,v 1.48 2009/06/13 06:46:42 rillig Exp $

DISTNAME=	gnustep-make-2.0.8
PKGREVISION=	2
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=core/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	GNUstep makefile package
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		objc
USE_TOOLS+=		csh
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		INSTALL_PROGRAM=${INSTALL_SCRIPT:Q}
CONFIGURE_ARGS+=	--disable-importing-config-file
CONFIGURE_ARGS+=	--with-layout=fhs
CONFIGURE_ARGS+=	--with-config-file=${PKG_SYSCONFDIR}/GNUstep.conf
MAKE_FILE=		GNUmakefile

CONF_FILES+=		${PREFIX}/share/examples/GNUstep/GNUstep.conf \
			${PKG_SYSCONFDIR}/GNUstep.conf

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "pth")
PTHREAD_LIBS+=		-lpth
.endif

CONFIGURE_ARGS+=	--with-thread-lib=${PTHREAD_LIBS:Q}

.include "gnustep.mk"

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

INSTALLATION_DIRS+=	share/GNUstep/Library
INSTALLATION_DIRS+=	share/GNUstep/Makefiles/${GNUSTEP_ARCH}
INSTALLATION_DIRS+=	share/GNUstep/Makefiles/Additional
INSTALLATION_DIRS+=	share/GNUstep/Makefiles/Auxiliary

.include "../../mk/bsd.pkg.mk"
