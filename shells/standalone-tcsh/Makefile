# $NetBSD: Makefile,v 1.4 2002/10/31 11:55:30 wiz Exp $
#

NO_MTREE=		YES

WRKSRC=			${WRKDIR}/${DISTNAME}
PKGNAME=		standalone-${DISTNAME}

.include "../../shells/tcsh/Makefile"

COMMENT:=		Standalone version of the ${COMMENT}

LDFLAGS+=		-static
LOCALBASE=		/
NLSDIR=			usr/share/nls
CONFIGURE_ARGS=		--prefix=${PREFIX} --bindir=/bin
CONFIGURE_ARGS+=	--mandir=/usr/share/man

DISTINFO_FILE=		${.CURDIR}/../../shells/tcsh/distinfo
PATCHDIR=		${.CURDIR}/../../shells/tcsh/patches
