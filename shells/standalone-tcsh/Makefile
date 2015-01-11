# $NetBSD: Makefile,v 1.24 2015/01/11 02:15:51 dholland Exp $
#

# FIXME: This is because of PREFIX=/ below.
CHECK_FILES_SUPPORTED=	no

PKGNAME=		standalone-${DISTNAME}

WRKSRC=			${WRKDIR}/${DISTNAME}
PATCHDIR=		${.CURDIR}/../../shells/tcsh/patches

# This package only makes sense on platforms that don't themselves ship tcsh
# in /bin. Otherwise it clobbers the native copy, which really isn't what
# anyone wants.
ONLY_FOR_PLATFORM+=	NetBSD-*-* OpenBSD-*-* SunOS-*-*

.include "../../shells/tcsh/Makefile"

INSTALLATION_DIRS+=	usr/share/man/man1

COMMENT:=		Standalone version of the Extended C-shell
MAINTAINER=		agc@NetBSD.org

# FIXME: Packages shall only install into ${LOCALBASE} or a subdirectory.
PREFIX=			/

NLSDIR=			usr/share/nls
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--bindir=/bin
CONFIGURE_ARGS+=	--mandir=/usr/share/man

DISTINFO_FILE=		${.CURDIR}/../../shells/tcsh/distinfo

.if ${OPSYS} != "SunOS"
LDFLAGS+=		-static
.endif
