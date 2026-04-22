# $NetBSD: Makefile,v 1.2 2026/04/22 23:17:35 js Exp $

DISTNAME=	fpc-3.2.2.source
PKGNAME=	${DISTNAME:S/.source//}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=freepascal/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.freepascal.org/
COMMENT=	Free Pascal and Object Pascal compiler
LICENSE=	gnu-gpl-v2

DISTFILES=	${DEFAULT_DISTFILES}
EXTRACT_ONLY=	${DEFAULT_DISTFILES}

.include "../../mk/bsd.prefs.mk"
.include "bootstrap.mk"

WRKSRC=			${WRKDIR}/${DISTNAME:S/.source//}
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake

_PKGSRC_MKPIE=		no # Avoid -pie for ld to fix build failure
CHECK_RELRO_SUPPORTED=	no

MAKE_ENV+=	FPC=${WRKDIR}/${PKGNAME_NOREV}.${MACHINE_ARCH}-${LOWER_OPSYS}/lib/fpc/${PKGVERSION_NOREV}/${COMPILER}
MAKE_ENV+=	LD_LIBRARY_PATH=${WRKDIR}/${PKGNAME_NOREV}.${MACHINE_ARCH}-${LOWER_OPSYS}/lib
MAKE_ENV+=	OVERRIDEVERSIONCHECK=1
MAKE_ENV+=	DIST_DESTDIR=${DESTDIR}
MAKE_ENV+=	INSTALL_PREFIX=${DESTDIR}${PREFIX}

PRINT_PLIST_AWK+=	{ gsub(/${MACHINE_ARCH}/, "$${MACHINE_ARCH}"); }
PRINT_PLIST_AWK+=	{ gsub(/${LOWER_OPSYS}/, "$${LOWER_OPSYS}"); }
PRINT_PLIST_AWK+=	{ gsub(/${COMPILER}/, "$${COMPILER}"); }
PLIST_SUBST+=		COMPILER=${COMPILER}

post-extract:
.if ${OPSYS} == "Darwin"
	mkdir ${WRKDIR}/bootstrap
	hdiutil attach ${WRKDIR}/*.dmg -mountpoint ${WRKDIR}/bootstrap
.  if !empty(MACHINE_PLATFORM:MDarwin-*-powerpc*)
	cd ${WRKDIR} && tar xf fpc-${PKGVERSION_NOREV}.powerpc-macosx.pkg/Contents/Archive.pax.gz
.  else
	cd ${WRKDIR} && xar -xf bootstrap/fpc-${PKGVERSION_NOREV}-intelarm64-macosx.mpkg/Contents/Packages/fpc-${PKGVERSION_NOREV}-intelarm64-macosx.pkg Payload
	cd ${WRKDIR} && tar -xzf Payload
.  endif
	diskutil eject force ${WRKDIR}/bootstrap
	mkdir ${WRKDIR}/${PKGNAME_NOREV}.${MACHINE_ARCH}-${LOWER_OPSYS}
	mv ${WRKDIR}/usr/local/* \
		${WRKDIR}/${PKGNAME_NOREV}.${MACHINE_ARCH}-${LOWER_OPSYS}
.else
	cd ${WRKDIR}/${PKGNAME_NOREV}.${MACHINE_ARCH}-${LOWER_OPSYS} && \
		${_EXTRACT_TAR} xf binary.${MACHINE_ARCH}-${LOWER_OPSYS}.tar
	cd ${WRKDIR}/${PKGNAME_NOREV}.${MACHINE_ARCH}-${LOWER_OPSYS} && \
		for f in `${FIND} . -type f -name "base.*.tar.gz" -print`; do \
			${_EXTRACT_TAR} zxf $$f; \
		done; \
		for f in `${FIND} . -type f -name "units-*.tar.gz" -print`; do \
			${_EXTRACT_TAR} zxf $$f; \
		done; \
		for f in `${FIND} . -type f -name "utils-*.tar.gz" -print`; do \
			${_EXTRACT_TAR} zxf $$f; \
		done;
.endif

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${LN} -sf ../lib/fpc/${PKGVERSION_NOREV}/${COMPILER} .

.include "../../mk/bsd.pkg.mk"
