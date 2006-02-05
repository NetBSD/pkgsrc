# $NetBSD: Makefile,v 1.10 2006/02/05 23:09:01 joerg Exp $
#

DISTNAME=		gens-rc3
PKGNAME=		gens-2.12rc3
PKGREVISION=		6
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gens/}

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://gens.consolemul.com/
COMMENT=		Sega Genesis emulator with Sega CD support

BUILD_DEPENDS+=		nasm-[0-9]*:../../devel/nasm

# contains i386 assembler sources
ONLY_FOR_PLATFORM=	*-*-i386

WRKSRC=			${WRKDIR}/GensForLinux
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

.include "../../devel/SDL/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gens
	${INSTALL_DATA} ${WRKSRC}/gens.txt ${PREFIX}/share/doc/gens

.include "../../mk/bsd.pkg.mk"
