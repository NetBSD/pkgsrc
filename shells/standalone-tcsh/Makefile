# $NetBSD: Makefile,v 1.7 2003/04/04 17:32:51 abs Exp $
#

NO_MTREE=		YES

PKGNAME=		standalone-${DISTNAME}
WRKSRC=			${WRKDIR}/${DISTNAME}

PKG_SHELL=		/bin/tcsh

.include "../../shells/tcsh/Makefile"

COMMENT:=		Standalone version of the Extended C-shell

LDFLAGS+=		-static
LOCALBASE=		/
NLSDIR=			usr/share/nls
CONFIGURE_ARGS=		--prefix=${PREFIX} --bindir=/bin
CONFIGURE_ARGS+=	--mandir=/usr/share/man

DISTINFO_FILE=		${.CURDIR}/../../shells/tcsh/distinfo
PATCHDIR=		${.CURDIR}/../../shells/tcsh/patches
