# $NetBSD: Makefile,v 1.2 2019/06/08 10:53:27 rillig Exp $

DISTNAME=		cflib-CVS-20130415
PKGNAME=		cross-freemint-${DISTNAME:S/CVS-//}
CATEGORIES=		cross
MASTER_SITES=		http://vincent.riviere.free.fr/soft/m68k-atari-mint/archives/
MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		http://vincent.riviere.free.fr/soft/m68k-atari-mint/
COMMENT=		CFLIB for FreeMiNT
EXTRACT_SUFX=		.tar.bz2

DEPENDS+=	cross-freemint-gcc-[0-9]*:../../cross/freemint-gcc

USE_TOOLS+=		gmake

FREEMINT_PREFIX=	${PREFIX}/cross-freemint

BUILD_DIRS=		cflib

INCLUDES+=		-I${BUILDLINK_PREFIX.cross-freemint-gemlib}/cross-freemint/include

MAKE_ENV+=		FREEMINT_PREFIX=${FREEMINT_PREFIX}

MAKE_FLAGS+=		INCLUDES=${INCLUDES}

BUILD_TARGET=		normal normal020 normalv4e

.include "../../cross/freemint-gemlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
