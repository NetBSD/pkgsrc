# $NetBSD: Makefile,v 1.28 2012/10/03 12:55:13 asau Exp $
#

DISTNAME=		gens-rc3
PKGNAME=		gens-2.12rc3
PKGREVISION=		21
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
USE_TOOLS+=		gmake pkg-config

INSTALLATION_DIRS+= share/doc/gens

.include "../../devel/SDL/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/gens.txt ${DESTDIR}${PREFIX}/share/doc/gens

.include "../../mk/bsd.pkg.mk"
