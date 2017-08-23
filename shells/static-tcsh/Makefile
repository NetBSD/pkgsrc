# $NetBSD: Makefile,v 1.9 2017/08/23 17:52:47 jlam Exp $
#

MAINTAINER=		agc@NetBSD.org

DISTINFO_FILE=		${.CURDIR}/../../shells/tcsh/distinfo
PATCHDIR=		${.CURDIR}/../../shells/tcsh/patches
PKGDIR=			${.CURDIR}/../../shells/tcsh
DESCR_SRC=		${.CURDIR}/../../shells/tcsh/DESCR ${.CURDIR}/DESCR

CONFLICTS=		tcsh-[0-9]*

PKGNAME=		static-${DISTNAME}
PKGREVISION=		3	# ALWAYS needs to be set; 0 if none.

.include "../../shells/tcsh/Makefile"

COMMENT:=		Statically-linked version of the ${COMMENT}

LDFLAGS+=		-static
