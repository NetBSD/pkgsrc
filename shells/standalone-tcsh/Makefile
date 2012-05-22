# $NetBSD: Makefile,v 1.23 2012/05/22 08:46:53 marino Exp $
#

# FIXME: This is because of PREFIX=/ below.
CHECK_FILES_SUPPORTED=	no

PKGNAME=		standalone-${DISTNAME}

WRKSRC=			${WRKDIR}/${DISTNAME}
PATCHDIR=		${.CURDIR}/../../shells/tcsh/patches

# DragonFly already has native /bin/tcsh
# This package is not restricted to ${LOCALBASE} and will replace system tcsh
# Instead, see shells/tcsh which installs at ${LOCALBASE}/bin/tcsh
NOT_FOR_PLATFORM+=	DragonFly-*-*

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
