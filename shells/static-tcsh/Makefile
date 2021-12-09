# $NetBSD: Makefile,v 1.17 2021/12/09 19:55:39 kim Exp $
#

PKGNAME=		static-${DISTNAME}

.include "../../shells/tcsh/Makefile.common"

MAINTAINER=		agc@NetBSD.org

PATCHDIR=		../../shells/tcsh/patches
PKGDIR=			../../shells/tcsh
DESCR_SRC=		../../shells/tcsh/DESCR DESCR

CONFLICTS=		tcsh-[0-9]*

COMMENT=		Statically-linked version of the Extended C-shell

.include "../../mk/bsd.pkg.mk"
