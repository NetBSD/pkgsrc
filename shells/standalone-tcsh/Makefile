# $NetBSD: Makefile,v 1.5 2002/11/17 09:02:01 salo Exp $
#

NO_MTREE=		YES

WRKSRC=			${WRKDIR}/${DISTNAME}
PKGNAME=		standalone-${DISTNAME}

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
