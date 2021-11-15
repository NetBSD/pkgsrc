# $NetBSD: Makefile,v 1.15 2021/11/15 19:56:03 kim Exp $
#

PKGNAME=		static-${DISTNAME}
PKGREVISION=		2

.include "../../shells/tcsh/Makefile.common"

MAINTAINER=		agc@NetBSD.org

PATCHDIR=		../../shells/tcsh/patches
PKGDIR=			../../shells/tcsh
DESCR_SRC=		../../shells/tcsh/DESCR DESCR

CONFLICTS=		tcsh-[0-9]*

COMMENT=		Statically-linked version of the Extended C-shell

.include "../../mk/bsd.pkg.mk"
