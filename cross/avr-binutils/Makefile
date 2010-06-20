# $NetBSD: Makefile,v 1.16 2010/06/20 16:23:56 tron Exp $

DISTNAME=		binutils-2.19.1
PKGNAME=		avr-binutils-2.19.1
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_GNU:=binutils/}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		GNU binutils for Atmel AVR 8-bit RISC microcontrollers

PKG_DESTDIR_SUPPORT=	user-destdir

USE_BZIP2=		yes
USE_TOOLS+=		gmake makeinfo
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_GNU_CONFIGURE_HOST=	no

CONFIGURE_ARGS+=	--disable-werror --target=avr

# Prevent the need to run texi2pod.pl and pod2man hence
# the need for perl as build dependency.
post-configure:
	cd ${WRKSRC};						\
	for f in ld/ldver.texi ld/ld.1 gas/doc/gasver.texi	\
	  gas/doc/as.1; do					\
		${TOUCH} $${f};					\
	done

.include "../../mk/bsd.pkg.mk"
