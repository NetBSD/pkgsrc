# $NetBSD: Makefile,v 1.3 2002/07/25 11:15:58 kim Exp $
#

NO_MTREE=		YES

.include "../../shells/tcsh/Makefile"

WRKSRC:=		${WRKDIR}/${DISTNAME}
PKGNAME:=		standalone-${DISTNAME}
COMMENT:=		Standalone version of the ${COMMENT}

LDFLAGS+=		-static
LOCALBASE=		/
NLSDIR=			usr/share/nls
CONFIGURE_ARGS=		--prefix=${PREFIX} --bindir=/bin
CONFIGURE_ARGS+=	--mandir=/usr/share/man

DISTINFO_FILE=		${.CURDIR}/../../shells/tcsh/distinfo
PATCHDIR=		${.CURDIR}/../../shells/tcsh/patches
