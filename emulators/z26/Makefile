# $NetBSD: Makefile,v 1.9 2012/10/03 12:55:23 asau Exp $
#

DISTNAME=		z26v213
PKGNAME=		z26-2.13
PKGREVISION=		3
CATEGORIES=		emulators games
MASTER_SITES=		http://www.whimsey.com/z26/

MAINTAINER=		xmor61@users.sourceforge.net
HOMEPAGE=		http://www.whimsey.com/z26/
COMMENT=		Atari 2600 Emulator

BUILD_DEPENDS+=		nasm-[0-9]*:../../devel/nasm

ONLY_FOR_PLATFORM+=	*-*-i386

WRKSRC=			${WRKDIR}/z26_snapshot-20040523
USE_TOOLS+=		gmake m4 perl
BUILD_TARGET=		netbsd
MAKE_ENV+=		INSTALL_BINDIR=${DESTDIR}${PREFIX}/bin
MAKE_ENV+=		INSTALL_MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
MAKE_FLAGS+=		INSTALL_USER=${ROOT_USER}
MAKE_FLAGS+=		INSTALL_GROUP=${ROOT_GROUP}

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
