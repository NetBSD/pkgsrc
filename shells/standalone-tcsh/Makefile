# $NetBSD: Makefile,v 1.6 2003/03/29 12:42:26 jmmv Exp $
#

NO_MTREE=		YES

PKGNAME=		standalone-${DISTNAME}
WRKSRC=			${WRKDIR}/${DISTNAME}

PKG_SHELL=		/bin/tcsh

.include "../../shells/tcsh/Makefile"

COMMENT:=		Standalone version of the ${COMMENT}

LDFLAGS+=		-static
LOCALBASE=		/
NLSDIR=			usr/share/nls
CONFIGURE_ARGS=		--prefix=${PREFIX} --bindir=/bin
CONFIGURE_ARGS+=	--mandir=/usr/share/man

DISTINFO_FILE=		${.CURDIR}/../../shells/tcsh/distinfo
PATCHDIR=		${.CURDIR}/../../shells/tcsh/patches
