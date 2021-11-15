# $NetBSD: Makefile,v 1.14 2021/11/15 17:11:58 kim Exp $
#

PKGNAME=		static-${DISTNAME}
PKGREVISION=		2

.include "../../shells/tcsh/Makefile.common"

MAINTAINER=		agc@NetBSD.org

PATCHDIR=		${.CURDIR}/../../shells/tcsh/patches
PKGDIR=			${.CURDIR}/../../shells/tcsh
DESCR_SRC=		${.CURDIR}/../../shells/tcsh/DESCR ${.CURDIR}/DESCR

CONFLICTS=		tcsh-[0-9]*

COMMENT=		Statically-linked version of the Extended C-shell

.include "../../mk/bsd.pkg.mk"
