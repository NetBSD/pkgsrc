# $NetBSD: Makefile,v 1.1.1.1 2005/02/01 21:51:12 jschauma Exp $

DISTNAME=		nss-3.9.2
CATEGORIES=		security
MASTER_SITES?=		ftp://ftp.mozilla.org/pub/mozilla.org/security/nss/releases/NSS_3_9_2_RTM/src/

MAINTAINER=		mjl@luckie.org.nz
HOMEPAGE=		http://www.mozilla.org/projects/security/pki/nss/
COMMENT=		Libraries to support development of security-enabled applications

BUILD_DEPENDS+=		zip>=2.3:../../archivers/zip

WRKSRC=			${WRKDIR}/${DISTNAME}/mozilla/security/nss

USE_BUILDLINK3=		YES
USE_PERL5=		build
USE_GNU_TOOLS+=		make
DIST=			${WRKSRC}/../../dist
BUILD_TARGET=		nss_build_all
MAKE_ENV=		BSD_LDOPTS="-L${LOCALBASE}/lib" BUILD_OPT=1
MAKE_ENV+=		LIBRUNPATH=${PREFIX}/lib

.include		"../../mk/bsd.prefs.mk"

CFLAGS+=		-I${LOCALBASE}/include/nspr

.if ${OBJECT_FMT} == "ELF"
SO_SUFFIX=		so
.elif ${OBJECT_FMT} == "Mach-O"
SO_SUFFIX=		dylib
.else
SO_SUFFIX=		so.1.0
.endif
PLIST_SUBST+=		SO_SUFFIX=${SO_SUFFIX}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/nss
	(cd ${DIST}/public && ${PAX} -Lrwpe . ${PREFIX}/include/nss/ )
	(cd ${DIST}/${OPSYS}${OS_VERSION}_OPT.OBJ/lib && \
		${PAX} -Lrwpe *.${SO_SUFFIX} ${PREFIX}/lib/ )

.include "../../devel/nspr/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

