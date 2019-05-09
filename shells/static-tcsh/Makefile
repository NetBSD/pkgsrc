# $NetBSD: Makefile,v 1.11 2019/05/09 11:32:36 leot Exp $
#

MAINTAINER=		agc@NetBSD.org

DISTINFO_FILE=		${.CURDIR}/../../shells/tcsh/distinfo
PATCHDIR=		${.CURDIR}/../../shells/tcsh/patches
PKGDIR=			${.CURDIR}/../../shells/tcsh
DESCR_SRC=		${.CURDIR}/../../shells/tcsh/DESCR ${.CURDIR}/DESCR

CONFLICTS=		tcsh-[0-9]*

PKGNAME=		static-${DISTNAME}
PKGREVISION=		0	# ALWAYS needs to be set; 0 if none.

# SunOS 5.10 stopped shipping static libraries.
NOT_FOR_PLATFORM+=	SunOS-5.1[0-9]-*

.include "../../shells/tcsh/Makefile"

COMMENT:=		Statically-linked version of the ${COMMENT}

LDFLAGS+=		-static
