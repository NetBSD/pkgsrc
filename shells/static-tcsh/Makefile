# $NetBSD: Makefile,v 1.16 2021/11/18 10:20:47 kim Exp $
#

PKGNAME=		static-${DISTNAME}
PKGREVISION=		3

.include "../../shells/tcsh/Makefile.common"

MAINTAINER=		agc@NetBSD.org

PATCHDIR=		../../shells/tcsh/patches
PKGDIR=			../../shells/tcsh
DESCR_SRC=		../../shells/tcsh/DESCR DESCR

CONFLICTS=		tcsh-[0-9]*

COMMENT=		Statically-linked version of the Extended C-shell

.include "../../mk/bsd.pkg.mk"
