# $NetBSD: Makefile,v 1.1.1.1 2004/12/30 19:49:08 kristerw Exp $
#

DISTNAME=		simulavr-0.1.2.1
CATEGORIES=		emulators
MASTER_SITES=		http://freesoftware.fsf.org/download/simulavr/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.nongnu.org/simulavr/
COMMENT=		Simulator for Atmel AVR microcontrollers

BUILD_DEPENDS+=		doxygen-*:../../devel/doxygen

CONFIGURE_ARGS+=	--disable-tests

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

# gcc 2.95 gives warnings that it cannot inline all functions.
BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../mk/bsd.pkg.mk"
