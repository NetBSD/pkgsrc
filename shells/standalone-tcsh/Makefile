# $NetBSD: Makefile,v 1.28 2017/08/23 17:52:47 jlam Exp $
#

# FIXME: This is because of PREFIX=/ below.
CHECK_FILES_SUPPORTED=	no
NOT_FOR_UNPRIVILEGED=	yes

PKGNAME=		standalone-${DISTNAME}
PKGREVISION=		2	# ALWAYS needs to be set; 0 if none.

WRKSRC=			${WRKDIR}/${DISTNAME}
PATCHDIR=		${.CURDIR}/../../shells/tcsh/patches

# This package only makes sense on platforms that don't themselves ship tcsh
# in /bin. Otherwise it clobbers the native copy, which really isn't what
# anyone wants.
ONLY_FOR_PLATFORM+=	NetBSD-*-* OpenBSD-*-* SunOS-*-*

.include "../../mk/bsd.prefs.mk"

.if ${OS_VARIANT} == "OmniOS"
NOT_FOR_PLATFORM+=	SunOS-*-*
.endif

.include "../../shells/tcsh/Makefile"

INSTALLATION_DIRS+=	usr/share/man/man1

COMMENT:=		Standalone version of the Extended C-shell
MAINTAINER=		agc@NetBSD.org

# FIXME: Packages shall only install into ${LOCALBASE} or a subdirectory.
PREFIX=			/
NOT_FOR_BULK_PLATFORM=	*-*-*

NLSDIR=			usr/share/nls
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--bindir=/bin
CONFIGURE_ARGS+=	--mandir=/usr/share/man

DISTINFO_FILE=		${.CURDIR}/../../shells/tcsh/distinfo

.if ${OPSYS} != "SunOS"
LDFLAGS+=		-static
.endif
