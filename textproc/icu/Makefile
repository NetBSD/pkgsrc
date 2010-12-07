# $NetBSD: Makefile,v 1.61 2010/12/07 17:58:13 adam Exp $

DISTNAME=	icu4c-4_6-src
PKGNAME=	icu-4.6
CATEGORIES=	textproc
MASTER_SITES=	http://download.icu-project.org/files/icu4c/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.icu-project.org/
COMMENT=	Robust and full-featured Unicode services

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/icu/source
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
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

.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD" || ${OPSYS} == "DragonFly"
PLIST_SUBST+=		MH_NAME=mh-bsd-gcc
.elif ${OPSYS} == "Linux"
PLIST_SUBST+=		MH_NAME=mh-linux
.elif ${OPSYS} == "SunOS"
.  if !empty(CC_VERSION:Mgcc*)
PLIST_SUBST+=		MH_NAME=mh-solaris-gcc
.  else
PLIST_SUBST+=		MH_NAME=mh-solaris
.  endif
.elif ${OPSYS} == "IRIX"
PLIST_SUBST+=		MH_NAME=mh-irix
.elif ${OPSYS} == "Darwin"
PLIST_SUBST+=		MH_NAME=mh-darwin
.else
# For unknown systems, set the filename to mh-unknown so that the user
# gets a warning about missing files.
PLIST_SUBST+=		MH_NAME=mh-unknown
.endif

.if ${OPSYS} == "Darwin"
SO_EXT=
SO_SUFFIX=.dylib
INSTALL_UNSTRIPPED=	yes
.else
SO_EXT=.so
SO_SUFFIX=
.endif
PLIST_SUBST+=	SO_SUFFIX=${SO_SUFFIX} SO_EXT=${SO_EXT}

.include "../../mk/bsd.pkg.mk"
