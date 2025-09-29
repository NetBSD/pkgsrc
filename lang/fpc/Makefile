# $NetBSD: Makefile,v 1.1 2025/09/29 14:13:00 ryoon Exp $

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

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${LN} -sf ../lib/fpc/${PKGVERSION_NOREV}/${COMPILER} .

.include "../../mk/bsd.pkg.mk"
