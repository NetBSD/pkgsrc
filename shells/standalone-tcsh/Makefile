# $NetBSD: Makefile,v 1.1.1.1 2001/07/27 19:52:45 agc Exp $
#

NO_MTREE=		YES

.include "../../shells/tcsh/Makefile"

WRKSRC:=		${WRKDIR}/${PKGNAME}
PKGNAME:=		standalone-${PKGNAME}
COMMENT:=		Standlone version of the ${COMMENT}

LDFLAGS+=		-static
LOCALBASE=		/
NLSDIR=			usr/share/nls
CONFIGURE_ARGS=		--prefix=${PREFIX} --bindir=/bin
CONFIGURE_ARGS+=	--mandir=/usr/share/man

DISTINFO_FILE=		${.CURDIR}/../../shells/tcsh/distinfo
PATCHDIR=		${.CURDIR}/../../shells/tcsh/patches
