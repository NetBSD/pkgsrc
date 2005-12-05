# $NetBSD: Makefile,v 1.16 2005/12/05 20:49:56 rillig Exp $

DISTNAME=		gcc-3.3.2003.05.11
PKGNAME=		avr-gcc-3.3.2003.05.11
PKGREVISION=		1
CATEGORIES=		cross
MASTER_SITES=		http://people.freebsd.org/~joerg/
EXTRACT_SUFX=		.tar.bz2
DISTFILES=		gcc-core+g++-3.3.2003.05.11${EXTRACT_SUFX} \
			${MAN_AUX}

MAINTAINER=		karlj@mdstud.chalmers.se
COMMENT=		GNU gcc-3.3 for Atmel AVR 8-bit RISC microcontrollers

DEPENDS+=		avr-binutils-[0-9]*:../../cross/avr-binutils
BUILD_DEPENDS+=		autoconf-[0-9]*:../../devel/autoconf
BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison

EXTRACT_ONLY=		gcc-core+g++-3.3.2003.05.11${EXTRACT_SUFX}

# Unfortunately, only some mirrors have it as a .bz2 file, while
# the original master site still uses .gz.
GNU_CONFIGURE=		yes
USE_BZIP2=		yes
USE_TOOLS+=		bison gmake lex perl tar
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--target=avr

MAN_AUX=		gcc-man.2003.05.11.gz

MAKE_FLAGS+=		LANGUAGES="c c++"
MAKE_ENV+=		MACHINE_ARCH=avr

pre-build:
		if perl -e 'use 1.10 Pod::Man' >/dev/null 2>/dev/null ; \
		then : ; \
		else \
			cd ${WRKSRC} ; \
			${TAR} -xvzf ${DISTDIR}/${MAN_AUX} ; \
		fi

.include "../../mk/bsd.pkg.mk"
