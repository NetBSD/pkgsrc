# $NetBSD: Makefile,v 1.23 2013/12/31 00:56:17 mef Exp $

DISTNAME=		binutils-2.23.2
PKGNAME=		${DISTNAME:S/^/avr-/}
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_GNU:=binutils/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		GNU binutils for Atmel AVR 8-bit RISC microcontrollers
LICENSE=		gnu-gpl-v3

# No need to use makeinfo - this package doesn't install the documentation.
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_GNU_CONFIGURE_HOST=	no

CONFIGURE_ARGS+=	--disable-werror --target=avr --disable-nls

AUTO_MKDIRS=		yes

# Prevent the need to run texi2pod.pl and pod2man hence
# the need for perl as build dependency.
post-configure:
	set -e;							\
	cd ${WRKSRC};						\
	for f in ld/ldver.texi ld/ld.1 gas/doc/gasver.texi	\
	  gas/doc/as.1; do					\
		${TOUCH} $${f};					\
	done

# emulator/simulavr wants libbfd.so or libbfd.a and bfd.h
#  --with-bfd=path  location of AVR-binutils version of libbfd install
#  where include/bfd.h and lib/libbfd.a are found (from binutils)
post-build:
	set -e;							\
	(cd ${WRKSRC}/bfd; ${GMAKE} all libbfd.a);

post-install:
	# Emulator/simulvar needs library files
	(cd ${WRKSRC}/bfd; 					\
	${GMAKE} install-exec install-data; 			\
	${LIBTOOL} --mode install ${INSTALL_DATA} libbfd.la ${DESTDIR}${PREFIX}/avr/lib;	\
	${INSTALL_DATA} bfd.h ${DESTDIR}${PREFIX}/avr/include;	\
	)
	# Rename to avoid conflict to native and other cross assembler.
	# and clang differs its path so, (the same as h8300-elf-binutils).
	# (SunOS 5.11 places at amd64 instead of x86_64)
	(cd ${DESTDIR}${PREFIX};				\
	for d in amd64/libiberty.a ${MACHINE_ARCH}/libiberty.a libiberty.a;	\
	  do if [ -f lib/$$d ]; then				\
		${MV}	lib/$$d	 avr/lib/libiberty.a;		\
		break;						\
	     fi;						\
	  done;	)
	# emulator/simulavr wants following header files
	(cd ${WRKSRC}/include;					\
	for f in ansidecl.h symcat.h; do			\
	  ${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/avr/include;	\
	done;	\
	)
.include "../../mk/bsd.pkg.mk"
