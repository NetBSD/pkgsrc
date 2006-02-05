# $NetBSD: Makefile,v 1.7 2006/02/05 23:09:02 joerg Exp $
#

DISTNAME=		simulavr-0.1.2.1
PKGREVISION=		2
CATEGORIES=		emulators
MASTER_SITES=		http://freesoftware.fsf.org/download/simulavr/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.nongnu.org/simulavr/
COMMENT=		Simulator for Atmel AVR microcontrollers

BROKEN_IN=		pkgsrc-2005Q4

BUILD_DEPENDS+=		avr-binutils-[0-9]*:../../cross/avr-binutils
BUILD_DEPENDS+=		avr-gcc-[0-9]*:../../cross/avr-gcc
BUILD_DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen

CONFIGURE_ARGS+=	--disable-tests

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

# gcc 2.95 gives warnings that it cannot inline all functions.
BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../mk/bsd.pkg.mk"
