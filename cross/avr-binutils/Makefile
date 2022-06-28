# $NetBSD: Makefile,v 1.36 2022/06/28 11:31:14 wiz Exp $

DISTNAME=		binutils-2.38
PKGNAME=		${DISTNAME:S/^/avr-/}
PKGREVISION=		1
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_GNU:=binutils/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		GNU binutils for Atmel AVR 8-bit RISC microcontrollers
LICENSE=		gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

USE_LANGUAGES=		c c++
# No need to use makeinfo - this package doesn't install the documentation.
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_GNU_CONFIGURE_HOST=	no

CONFIGURE_ARGS+=	--enable-deterministic-archives
CONFIGURE_ARGS+=	--disable-lto
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--disable-werror
CONFIGURE_ARGS+=	--target=avr
CONFIGURE_ARGS+=	--with-system-zlib

AUTO_MKDIRS=		yes

TEST_DEPENDS=		dejagnu>=1.6.2:../../devel/dejagnu
TEST_TARGET=		check

# Prevent the need to run texi2pod.pl and pod2mane
# hence the need for perl as build dependency.
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
	# emulators/simulvar needs library files
	(cd ${WRKSRC}/bfd; 					\
	${GMAKE} install-exec install-data; 			\
	${LIBTOOL} --mode install ${INSTALL_DATA} libbfd.la	\
	  ${DESTDIR}${PREFIX}/avr/lib;				\
	${INSTALL_DATA} bfd.h ${DESTDIR}${PREFIX}/avr/include;	\
	)
	# emulators/simulavr wants libiberty
	(cd ${WRKSRC}/libiberty ;				\
	${INSTALL_DATA} libiberty.* ${DESTDIR}${PREFIX}/avr/lib/libiberty	\
	)
	# emulators/simulavr wants following header files
	(cd ${WRKSRC}/include;					\
	for f in ansidecl.h symcat.h diagnostics.h ; do			\
	  ${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/avr/include;	\
	done;							\
	)
	# Plugins may collide with other binutils flavours
	${MV} ${DESTDIR}${PREFIX}/lib/bfd-plugins		\
	  ${DESTDIR}${PREFIX}/avr/lib/

BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.3
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
