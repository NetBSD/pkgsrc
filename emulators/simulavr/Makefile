# $NetBSD: Makefile,v 1.9 2006/03/04 21:29:36 jlam Exp $
#

DISTNAME=		simulavr-0.1.2.1
PKGREVISION=		3
CATEGORIES=		emulators
MASTER_SITES=		http://freesoftware.fsf.org/download/simulavr/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.nongnu.org/simulavr/
COMMENT=		Simulator for Atmel AVR microcontrollers

BUILD_DEPENDS+=		avr-binutils-[0-9]*:../../cross/avr-binutils
BUILD_DEPENDS+=		avr-gcc-[0-9]*:../../cross/avr-gcc
BUILD_DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen

CONFIGURE_ARGS+=	--disable-tests

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

# gcc 2.95 gives warnings that it cannot inline all functions.
BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../mk/bsd.pkg.mk"
