# $NetBSD: Makefile,v 1.1.1.1 2003/07/16 20:14:20 wennmach Exp $
# FreeBSD Id: ports/devel/avr-gcc/Makefile,v 1.24 2003/05/11 19:32:20 joerg Exp

DISTNAME=		gcc-3.3.2003.05.11
PKGNAME=		avr-gcc-3.3.2003.05.11
CATEGORIES=		cross
MASTER_SITES=		http://people.freebsd.org/~joerg/
EXTRACT_SUFX=		.tar.bz2
DISTFILES=		gcc-core+g++-3.3.2003.05.11${EXTRACT_SUFX} \
			${MAN_AUX}

MAINTAINER=		karl@mdstud.chalmers.se
COMMENT=		FSF gcc-3.3 for Atmel AVR 8-bit RISC microcontrollers

BUILD_DEPENDS+=		avr-binutils:../../cross/avr-binutils
BUILD_DEPENDS+=		autoconf:../../devel/autoconf
BUILD_DEPENDS+=		bison:../../devel/bison

EXTRACT_ONLY=		gcc-core+g++-3.3.2003.05.11${EXTRACT_SUFX}

# Unfortunately, only some mirrors have it as a .bz2 file, while
# the original master site still uses .gz.
GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_PERL5_BUILD=	yes
USE_BZIP2=		yes
USE_GMAKE=		yes
USE_BISON=		yes
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS=		--target=avr --prefix=${PREFIX}

MAN_AUX=		gcc-man.2003.05.11.gz

MAKE_FLAGS=		LANGUAGES="c c++"
MAKE_ENV=		MACHINE_ARCH=avr

pre-build:
		if perl -e 'use 1.10 Pod::Man' >/dev/null 2>/dev/null ; \
		then : ; \
		else \
			cd ${WRKSRC} ; \
			${TAR} -xvzf ${DISTDIR}/${MAN_AUX} ; \
		fi

.include "../../mk/bsd.pkg.mk"
