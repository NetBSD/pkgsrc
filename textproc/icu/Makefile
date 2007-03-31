# $NetBSD: Makefile,v 1.53 2007/03/31 15:36:57 obache Exp $
#

DISTNAME=	icu4c-3_6-src
PKGNAME=	icu-3.6
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.software.ibm.com/software/globalization/icu/${PKGVERSION}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.icu-project.org/
COMMENT=	Robust and full-featured Unicode services

WRKSRC=			${WRKDIR}/${PKGBASE}/source
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
TEST_TARGET=		check
UNLIMIT_RESOURCES+=	datasize

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-static
CONFIGURE_ENV+=		U_MAKE=${TOOLS_GMAKE:Q}

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
SO_SUFFIX=dylib
.else
SO_SUFFIX=so
.endif
PLIST_SUBST+=	SO_SUFFIX=${SO_SUFFIX}

.include "../../mk/bsd.pkg.mk"
