# $NetBSD: Makefile,v 1.2 2019/06/08 10:53:27 rillig Exp $

DISTNAME=		gemlib-CVS-20130415
PKGNAME=		cross-freemint-${DISTNAME:S/CVS-//}
CATEGORIES=		cross
MASTER_SITES=		http://vincent.riviere.free.fr/soft/m68k-atari-mint/archives/
MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		http://vincent.riviere.free.fr/soft/m68k-atari-mint/
COMMENT=		GEMlib for FreeMiNT
EXTRACT_SUFX=		.tar.bz2

MAKE_JOBS_SAFE=		no

DEPENDS+=	cross-freemint-gcc-[0-9]*:../../cross/freemint-gcc

USE_TOOLS+=		gmake

FREEMINT_PREFIX=	${PREFIX}/cross-freemint

MAKE_ENV+=		FREEMINT_PREFIX=${FREEMINT_PREFIX}

BUILD_DIRS=		gemlib

.include "../../cross/freemint-mintbin/buildlink3.mk"
#.include "../../cross/freemint-mintlib/buildlink3.mk"
#.include "../../cross/freemint-pml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
