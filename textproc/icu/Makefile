# $NetBSD: Makefile,v 1.67 2012/02/01 23:53:32 wiz Exp $

DISTNAME=	icu4c-4_8_1-src
PKGNAME=	${DISTNAME:S/4c//:S/-src//:S/_/./g}
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://download.icu-project.org/files/icu4c/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.icu-project.org/
COMMENT=	Robust and full-featured Unicode services
LICENSE=	mit

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
INSTALL_UNSTRIPPED=	yes
.endif

.include "../../mk/bsd.pkg.mk"
