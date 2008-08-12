# $NetBSD: Makefile,v 1.21 2008/08/12 14:51:45 joerg Exp $
#

# FIXME: This is because of PREFIX=/ below.
CHECK_FILES_SUPPORTED=	no

NO_MTREE=		YES

PKGNAME=		standalone-${DISTNAME}

WRKSRC=			${WRKDIR}/${DISTNAME}
PATCHDIR=		${.CURDIR}/../../shells/tcsh/patches

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
