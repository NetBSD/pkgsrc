# $NetBSD: Makefile,v 1.37 2024/04/26 11:48:09 micha Exp $

DISTNAME=		binutils-2.42
PKGNAME=		${DISTNAME:S/^/avr-/}
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_GNU:=binutils/}
EXTRACT_SUFX=		.tar.lz

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		GNU binutils for Atmel AVR 8-bit RISC microcontrollers
LICENSE=		gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

USE_LANGUAGES=		c c++
# No need to use makeinfo - this package doesn't install the documentation.
USE_TOOLS+=		gmake perl
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

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/avr/lib/ldscripts/stamp
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
	for f in ansidecl.h symcat.h diagnostics.h ; do		\
	  ${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/avr/include;	\
	done;							\
	)
	# Plugins may collide with other binutils flavours
	${MV} ${DESTDIR}${PREFIX}/lib/bfd-plugins		\
	  ${DESTDIR}${PREFIX}/avr/lib/

BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.3
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
