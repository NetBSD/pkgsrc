# $NetBSD: Makefile,v 1.41 2022/03/03 07:30:47 nia Exp $
#

# FIXME: This is because of PREFIX=/ below.
CHECK_FILES_SUPPORTED=	no
NOT_FOR_UNPRIVILEGED=	yes

PKGNAME=		standalone-${DISTNAME}

PATCHDIR=		../../shells/tcsh/patches
PKGDIR=			../../shells/tcsh
DESCR_SRC=		../../shells/tcsh/DESCR DESCR

# This package only makes sense on platforms that don't themselves ship tcsh
# in /bin. Otherwise it clobbers the native copy, which really isn't what
# anyone wants.
ONLY_FOR_PLATFORM+=	NetBSD-*-* OpenBSD-*-* SunOS-*-*

.include "../../mk/bsd.prefs.mk"

.if "${OPSYS}" == "NetBSD" && !defined(OPSYS_HAS_STATIC_PIE)
MKPIE_SUPPORTED= no
.endif

.if ${OS_VARIANT} == "OmniOS"
NOT_FOR_PLATFORM+=	SunOS-*-*
.endif

.include "../../shells/tcsh/Makefile.common"
.include "../../mk/bsd.pkg.mk"

COMMENT:=		Standalone version of the Extended C-shell
MAINTAINER=		agc@NetBSD.org

# FIXME: Packages shall only install into ${LOCALBASE} or a subdirectory.
PREFIX=			/
PKGMANDIR=		usr/share/man
EGDIR=			usr/share/examples/tcsh
NLSDIR=			usr/share/nls
NOT_FOR_BULK_PLATFORM=	*-*-*

CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--bindir=${PREFIX:S/\/$//:Q}/bin
CONFIGURE_ARGS+=	--localedir=${PREFIX:S/\/$//:Q}/${NLSDIR}
CONFIGURE_ARGS+=	--mandir=${PREFIX:S/\/$//:Q}/${PKGMANDIR}

PLIST_AWK+=		-f ${.CURDIR}/plist-examples.awk
PLIST_AWK_ENV+=		EGDIR=${EGDIR}

PLIST_AWK+=		-f ${.CURDIR}/plist-nls.awk
PLIST_AWK_ENV+=		NLSDIR=${NLSDIR}
