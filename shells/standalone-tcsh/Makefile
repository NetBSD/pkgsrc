# $NetBSD: Makefile,v 1.2 2001/07/27 20:32:01 agc Exp $
#

NO_MTREE=		YES

.include "../../shells/tcsh/Makefile"

WRKSRC:=		${WRKDIR}/${PKGNAME}
PKGNAME:=		standalone-${PKGNAME}
COMMENT:=		Standalone version of the ${COMMENT}

LDFLAGS+=		-static
LOCALBASE=		/
NLSDIR=			usr/share/nls
CONFIGURE_ARGS=		--prefix=${PREFIX} --bindir=/bin
CONFIGURE_ARGS+=	--mandir=/usr/share/man

DISTINFO_FILE=		${.CURDIR}/../../shells/tcsh/distinfo
PATCHDIR=		${.CURDIR}/../../shells/tcsh/patches
