# $NetBSD: Makefile,v 1.2.4.1 2002/07/22 17:11:22 agc Exp $
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

pre-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/bin
