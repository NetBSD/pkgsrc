# $NetBSD: Makefile,v 1.1.1.1 2004/07/26 18:23:22 dillo Exp $
#

DISTNAME=		gens-rc3
PKGNAME=		gens-2.12rc3
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gens/}

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://gens.consolemul.com/
COMMENT=		Sega Genesis emulator with Sega CD support

BUILD_DEPENDS+=		nasm-[0-9]*:../../devel/nasm

# contains i386 assembler sources
ONLY_FOR_PLATFORM=	*-i386

WRKSRC=			${WRKDIR}/GensForLinux
USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

.include "../../devel/SDL/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gens
	${INSTALL_DATA} ${WRKSRC}/gens.txt ${PREFIX}/share/doc/gens

.include "../../mk/bsd.pkg.mk"
