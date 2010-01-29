# $NetBSD: Makefile,v 1.16 2010/01/29 22:58:10 joerg Exp $
#

DISTNAME=		simulavr-0.1.2.1
PKGREVISION=		3
CATEGORIES=		emulators
MASTER_SITES=		http://download.savannah.nongnu.org/releases/simulavr/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.nongnu.org/simulavr/
COMMENT=		Simulator for Atmel AVR microcontrollers

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=		avr-binutils-[0-9]*:../../cross/avr-binutils
BUILD_DEPENDS+=		avr-gcc-[0-9]*:../../cross/avr-gcc
BUILD_DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen

CONFIGURE_ARGS+=	--disable-tests
CONFIGURE_ENV+=		ac_cv_prog_has_texi2dvi=yes ac_cv_prog_has_texi2html=yes
USE_TOOLS+=		makeinfo

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
INFO_FILES=		yes

# gcc 2.95 gives warnings that it cannot inline all functions.
BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../mk/bsd.pkg.mk"
