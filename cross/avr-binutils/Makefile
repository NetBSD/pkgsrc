# $NetBSD: Makefile,v 1.11 2005/12/05 20:49:56 rillig Exp $

DISTNAME=		binutils-2.13.2.1
PKGNAME=		avr-binutils-2.13.2.1
PKGREVISION=		1
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_GNU:=binutils/}

MAINTAINER=		karlj@mdstud.chalmers.se
COMMENT=		GNU binutils for Atmel AVR 8-bit RISC microcontrollers

USE_BZIP2=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_MAKEINFO=		YES

CONFIGURE_ARGS+=	--target=avr

# Prevent the need to run texi2pod.pl and pod2man hence
# the need for perl as build dependency.
post-configure:
	cd ${WRKSRC};						\
	for f in ld/ldver.texi ld/ld.1 gas/doc/gasver.texi	\
	  gas/doc/as.1; do					\
		${TOUCH} $${f};					\
	done

.include "../../mk/bsd.pkg.mk"
