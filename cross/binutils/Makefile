# $NetBSD: Makefile,v 1.33 2004/04/24 13:53:37 wiz Exp $
#
# GNU binutils configured to hold `as many targets as the cross system is
# capable of using'.  Configures and builds everything except gas, which
# gets built at cross-pkg build time (it's target specific).

DISTNAME=		binutils-2.9.1
PKGNAME=		cross-binutils-2.9.1.2
CATEGORIES=		cross lang
MASTER_SITES=		${MASTER_SITE_GNU:=binutils/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnu.org/
COMMENT=		Unified GNU binutils for cross build environments

USE_BUILDLINK2=		yes
USE_CROSSBASE=		yes
USE_GNU_TOOLS+=		m4
USE_LIBTOOL=		yes

CONFIG_GUESS_OVERRIDE=	# empty
CONFIG_SUB_OVERRIDE=	# empty
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-64-bit-bfd
CONFIGURE_ARGS+=	--enable-targets=${ENABLE_TARGETS_LIST} \
			--target=i386-linux
# --target above ensures that --host is not included as default
MAKE_ARGS+=		CFLAGS="${CFLAGS}"
ALL_TARGET=		all-binutils all-ld

PLIST_SUBST=		LOCALBASE=${LOCALBASE}

BINDIR=			${PREFIX}/libexec/binutils

# due to /bin/sh restriction, we can accomodate no more archs
ENABLE_TARGETS+=	alpha-netbsd arm-netbsd \
			i386-cygwin32 i386-elf i386-go32 i386-linux \
			i386-netbsd i386-netware \
			m68k-elf m68k-netbsd m68k-netbsdelf m68k-sunos4 \
			mipseb-netbsd mipsel-netbsd \
			powerpc-eabi powerpcle-eabi \
			sparc-netbsd sparc-solaris2 sparc-sunos4 \
			sh-netbsdcoff shel-netbsdcoff

# this breaks the `sparc-solaris2' target (which adds sparc_elf32
# which we use for the `sparc-netbsdelf' target
#ENABLE_TARGETS+=	sparc64-elf

# make sure configure/Makefile.in is newer than configure.in/Makefile.am
post-patch:
	${FIND} ${WRKSRC} -name configure -print | ${XARGS} ${TOUCH}
	${FIND} ${WRKSRC} -name Makefile.in -print | ${XARGS} ${TOUCH}

# check that path does not contain cwd
pre-configure:
	@cd ${WRKDIR};							\
	${LN} -s ${CAT} ld;						\
	whichld=`${TYPE} ld | ${AWK} '{ print $$NF }'`;			\
	${RM} -f ld;							\
	if [ "X$$whichld" = "X./ld" ]; then				\
		${ECHO} "Warning - \".\" is present in your path \"${PATH}\". Configuration step will fail"; \
		${ECHO} "Please remove \".\" from your path, so that the correct ld executable will be found."; \
		${FALSE};						\
	fi;								\

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
	${INSTALL_SCRIPT} ${WRKSRC}/cross-env ${BINDIR}
	${LN} -s ${BINDIR}/cross-env ${LOCALBASE}/bin/cross-env

post-build:
	${SED} -e 's|@@PREFIX@@|${PREFIX}|' < ${FILESDIR}/cross-env > \
		${WRKSRC}/cross-env

.include "../../mk/bsd.pkg.mk"

ENABLE_TARGETS_LIST!=	${ECHO} "${ENABLE_TARGETS}" | ${SED} "s/[ 	][ 	]*/,/g;s/^,*//"

.if defined(EXTRACT_USING_PAX)
DONT_EXTRACT!=		${AWK} -- '{ ORS=" "; print $1 }' < ${FILESDIR}/exclude
EXTRACT_ELEMENTS=	-c ${DONT_EXTRACT}
.else
EXTRACT_ELEMENTS=	-X ${FILESDIR}/exclude
.endif
