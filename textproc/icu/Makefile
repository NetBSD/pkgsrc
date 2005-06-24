# $NetBSD: Makefile,v 1.41 2005/06/24 16:44:15 kristerw Exp $
#

DISTNAME=	icu-3.2
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.software.ibm.com/software/globalization/icu/${PKGVERSION}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://ibm.com/software/globalization/icu/
COMMENT=	Robust and full-featured Unicode services

WRKSRC=			${WRKDIR}/${PKGBASE}/source
USE_TOOLS+=		gmake
USE_PKGINSTALL=		YES
USE_LANGUAGES=		c c++
TEST_TARGET=		check

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-static
CONFIGURE_ENV+=		U_MAKE="${TOOLS_GMAKE}"

# ICU's configure script will automatically append "/icu" to the sysconfdir.
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}
PKG_SYSCONFSUBDIR=	icu

CONVRTRS_EG=		${CONVRTRS_EG_DIR}/convrtrs.txt
CONVRTRS_EG_DIR=	${PREFIX}/share/examples/icu

SUPPORT_FILES+=		${CONVRTRS_EG} ${PKG_SYSCONFDIR}/convrtrs.txt

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} != "native"
CONFIGURE_ARGS+=	--disable-threads
.endif

.include "../../mk/compiler.mk"

.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD"
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

post-install:
	${INSTALL_DATA_DIR} ${CONVRTRS_EG_DIR}
	${INSTALL_DATA} ${WRKSRC}/data/mappings/convrtrs.txt ${CONVRTRS_EG}

.include "../../mk/bsd.pkg.mk"
