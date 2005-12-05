# $NetBSD: Makefile,v 1.2 2005/12/05 20:50:13 rillig Exp $
#

DISTNAME=		z26v213
PKGNAME=		z26-2.13
CATEGORIES=		emulators games
MASTER_SITES=		http://www.whimsey.com/z26/

MAINTAINER=		xmor61@users.sourceforge.net
HOMEPAGE=		http://www.whimsey.com/z26/
COMMENT=		Atari 2600 Emulator

BUILD_DEPENDS+=		nasm-[0-9]*:../../devel/nasm

ONLY_FOR_PLATFORM+=	*-*-i386

WRKSRC=			${WRKDIR}/z26_snapshot-20040523
USE_TOOLS+=		gmake perl
BUILD_TARGET=		netbsd
MAKE_ENV+=		"INSTALL_BINDIR=${PREFIX}/bin"
MAKE_ENV+=		"INSTALL_MANDIR=${PREFIX}/man/man1"

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
