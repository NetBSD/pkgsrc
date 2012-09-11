# $NetBSD: Makefile,v 1.6 2012/09/11 19:47:01 asau Exp $

PKGNAME=		sapcar-7.00
CATEGORIES=		archivers
EXTRACT_SUFX=		# empty

NOT_FOR_PLATFORM+=	DragonFly-*-*

.include "../../emulators/sap/Makefile.common"

.if ${SAP_OPSYS} == "linux"
.if ${SAP_ARCH} == "x86_64"
DISTNAME=		SAPCAR_0-10003690.exe
.elif ${SAP_ARCH} == "i386"
DISTNAME=		SAPCAR_0-10003688.exe
.elif ${SAP_ARCH} == "powerpc64"
DISTNAME=		SAPCAR_0-10003687.exe
.elif ${SAP_ARCH} == "ia64"
DISTNAME=		SAPCAR_0-10003689.exe
.else
BROKEN=		Architecture ${MACHINE_ARCH} on this platform not supported
.endif
.elif ${SAP_OPSYS} == "aix"
.if ${SAP_ARCH} == "powerpc"
DISTNAME=		SAPCAR_0-10003699.exe
.else
BROKEN=		Architecture ${MACHINE_ARCH} on this platform not supported
.endif
.elif ${SAP_OPSYS} == "hpux"
.if ${SAP_ARCH} == "ia64"
DISTNAME=		SAPCAR_0-10003682.exe
.elif ${SAP_ARCH} == "hppa"
DISTNAME=		SAPCAR_0-10003683.exe
.else
BROKEN=		Architecture ${MACHINE_ARCH} on this platform not supported
.endif
.elif ${SAP_OPSYS} == "solaris"
.if ${SAP_ARCH} == "x86_64"
DISTNAME=		SAPCAR_0-10003701.exe
.elif ${SAP_ARCH} == "sparc64"
DISTNAME=		SAPCAR_0-10003702.exe
.else
BROKEN=		Architecture ${MACHINE_ARCH} on this platform not supported
.endif
.elif ${SAP_OPSYS} == "interix"
# Note: only native windows and interix is supported here - maybe MKS Toolkit
# Cygwin must fail!
.if ${SAP_ARCH} == "x86_64"
DISTNAME=		SAPCAR_0-10003696.exe
.elif ${SAP_ARCH} == "i586"
DISTNAME=		SAPCAR_0-10003694.exe
.elif ${SAP_ARCH} == "ia64"
DISTNAME=		SAPCAR_0-10003695.exe
.else
BROKEN=		Architecture ${MACHINE_ARCH} on platform ${OPSYS} not supported
.endif
.else
BROKEN=		Platform ${OPSYS} not supported
.endif

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		SAP archiver
LICENSE=		sap-license

.if !exists(DOWNLOADED_DISTFILE) && make(pbulk-index)
PKG_FAIL_REASON+=	"Missing distfile"
.endif

RESTRICTED=		Only unmodified original package can be distributed
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

WRKSRC=			${WRKDIR}/SAPCAR
BUILD_DIRS=		# empty

NO_CONFIGURE=		yes
NO_BUILD=		yes

do-extract:
	${MKDIR} ${WRKSRC:Q}
.for f in ${DISTNAME}
	${CP} ${_DISTDIR:Q}/${f:Q} ${WRKSRC:Q}/${f:Q}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/${DISTNAME} ${PREFIX:Q}/bin/SAPCAR

.include "../../mk/bsd.pkg.mk"
