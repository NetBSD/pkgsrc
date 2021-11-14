# $NetBSD: Makefile,v 1.13 2021/11/14 22:15:13 kim Exp $
#

.include "../../shells/tcsh/Makefile.common"

MAINTAINER=		agc@NetBSD.org

DISTINFO_FILE=		${.CURDIR}/../../shells/tcsh/distinfo
PATCHDIR=		${.CURDIR}/../../shells/tcsh/patches
PKGDIR=			${.CURDIR}/../../shells/tcsh
DESCR_SRC=		${.CURDIR}/../../shells/tcsh/DESCR ${.CURDIR}/DESCR

CONFLICTS=		tcsh-[0-9]*

PKGNAME=		static-${DISTNAME}
PKGREVISION=		1

# SunOS 5.10 stopped shipping static libraries.
NOT_FOR_PLATFORM+=	SunOS-5.1[0-9]-*

COMMENT:=		Statically-linked version of the ${COMMENT}

LDFLAGS+=		-static

.include "../../mk/bsd.pkg.mk"
