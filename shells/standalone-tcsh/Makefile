# $NetBSD: Makefile,v 1.12 2004/01/11 23:06:54 grant Exp $
#

NO_MTREE=		YES

PKGNAME=		standalone-${DISTNAME}
WRKSRC=			${WRKDIR}/${DISTNAME}

PKG_SHELL=		/bin/tcsh

.include "../../shells/tcsh/Makefile"

COMMENT:=		Standalone version of the Extended C-shell

PATCH:=			${PATCH}
PKG_INFO:=		${PKG_INFO}
PKG_CREATE:=		${PKG_CREATE}
PREFIX=			/
NLSDIR=			usr/share/nls
CONFIGURE_ARGS=		--prefix=${PREFIX} --bindir=/bin
CONFIGURE_ARGS+=	--mandir=/usr/share/man

DISTINFO_FILE=		${.CURDIR}/../../shells/tcsh/distinfo
PATCHDIR=		${.CURDIR}/../../shells/tcsh/patches

.if ${OPSYS} != "SunOS"
LDFLAGS+=		-static
.endif
