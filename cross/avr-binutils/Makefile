# $NetBSD: Makefile,v 1.1.1.1 2003/07/15 21:46:26 wennmach Exp $
# FreeBSD Id: ports/devel/avr-binutils/Makefile,v 1.9 2003/03/07 06:00:08 ade Exp

DISTNAME=		binutils-2.13.2.1
PKGNAME=		avr-binutils-2.13.2.1
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_SOURCEWARE:=binutils/releases/}

MAINTAINER=		karlj@mdstud.chalmers.se
COMMENT=		GNU binutils for Atmel AVR 8-bit RISC microcontrollers

USE_BZIP2=		yes
USE_GMAKE=		yes
CONFIGURE_ARGS=		--target=avr --prefix=${PREFIX}
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
LIBTOOLFILES=		configure bfd/configure binutils/configure \
			etc/configure gas/configure gprof/configure \
			intl/configure ld/configure libiberty/configure \
			opcodes/configure

.include "../../mk/bsd.pkg.mk"
