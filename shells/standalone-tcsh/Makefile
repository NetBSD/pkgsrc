# $NetBSD: Makefile,v 1.19 2005/12/19 14:12:31 abs Exp $
#

NO_MTREE=		YES

PKGNAME=		standalone-${DISTNAME}

WRKSRC=			${WRKDIR}/${DISTNAME}
PATCHDIR=		${.CURDIR}/../../shells/tcsh/patches

.include "../../shells/tcsh/Makefile"

COMMENT:=		Standalone version of the Extended C-shell
MAINTAINER=		agc@NetBSD.org

PREFIX=			/
NLSDIR=			usr/share/nls
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--bindir=/bin
CONFIGURE_ARGS+=	--mandir=/usr/share/man

DISTINFO_FILE=		${.CURDIR}/../../shells/tcsh/distinfo

.if ${OPSYS} != "SunOS"
LDFLAGS+=		-static
.endif
