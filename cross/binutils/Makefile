# $NetBSD: Makefile,v 1.16 1999/12/18 02:14:39 wrstuden Exp $
#
# GNU binutils configured to hold `as many targets as the cross system is
# capable of using'.  Configures and builds everything except gas, which
# gets built at cross-pkg build time (it's target specific).

DISTNAME=		binutils-2.9.1
PKGNAME=		cross-binutils-2.9.1.1
CATEGORIES=		cross lang
MASTER_SITES=		${MASTER_SITE_GNU:=binutils/}

MAINTAINER=		tv@netbsd.org
HOMEPAGE=		http://www.gnu.org/

USE_CROSSBASE=		yes
USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-64-bit-bfd
CONFIGURE_ARGS+=	--enable-targets=${ENABLE_TARGETS_LIST} \
			--target=i386-linux
# --target above ensures that --host is not included as default
MAKE_ARGS+=		CFLAGS="${CFLAGS}"
ALL_TARGET=		all-binutils all-ld

BINDIR=			${PREFIX}/libexec/binutils

ENABLE_TARGETS+=	alpha-netbsd arm-netbsd \
			i386-cygwin32 i386-elf i386-go32 i386-linux \
			i386-netbsd i386-netware \
			m68k-elf m68k-netbsd m68k-sunos4 \
			mips-dec-netbsd \
			powerpc-eabi powerpcle-eabi \
			sparc-netbsd sparc-solaris2 sparc-sunos4

# this breaks the `sparc-solaris2' target (which adds sparc_elf32
# which we use for the `sparc-netbsdelf' target
#ENABLE_TARGETS+=	sparc64-elf

# we use MKDIR, not INSTALL_PROGRAM_DIR, deliberately.
do-install:
	${MKDIR} ${BINDIR} ${PREFIX}/lib/ldscripts ${PREFIX}/include
	@${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/binutils/addr2line ${BINDIR}
	@${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/binutils/ar ${BINDIR}
	@${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/binutils/dlltool ${BINDIR}
	@${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/ld/ld-new ${BINDIR}/ld
	@${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/binutils/nlmconv ${BINDIR}
	@${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/binutils/nm-new ${BINDIR}/nm
	@${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/binutils/objcopy ${BINDIR}
	@${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/binutils/objdump ${BINDIR}
	@${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/binutils/ranlib ${BINDIR}
	@${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/binutils/size ${BINDIR}
	@${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/binutils/strings ${BINDIR}
	@${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/binutils/strip-new ${BINDIR}/strip
	@${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/binutils/windres ${BINDIR}
	@${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/bfd/libbfd.la ${PREFIX}/lib
	@${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/opcodes/libopcodes.la ${PREFIX}/lib
	@${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/libiberty/libiberty.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/include/ansidecl.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/bfd/bfd.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/ld/ldscripts/* ${PREFIX}/lib/ldscripts

.include "../../mk/bsd.pkg.mk"

ENABLE_TARGETS_LIST!=	${ECHO} "${ENABLE_TARGETS}" | ${SED} "s/[ 	][ 	]*/,/g;s/^,*//"

.if defined(EXTRACT_USING_PAX)
DONT_EXTRACT!=		${AWK} -- '{ ORS=" "; print $1 }' < ${FILESDIR}/exclude
EXTRACT_ELEMENTS=	-c ${DONT_EXTRACT}
.else
EXTRACT_ELEMENTS=	-X ${FILESDIR}/exclude
.endif
