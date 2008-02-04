# $NetBSD: Makefile,v 1.51 2008/02/04 19:52:55 tnn Exp $
#
# GNU binutils configured to hold `as many targets as the cross system is
# capable of using'.  Configures and builds everything except gas, which
# gets built at cross-pkg build time (it's target specific).

DISTNAME=		binutils-2.17
PKGREVISION=		1
PKGNAME=		cross-binutils-2.17.0.0
CATEGORIES=		cross lang
MASTER_SITES=		${MASTER_SITE_GNU:=binutils/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/
COMMENT=		Unified GNU binutils for cross build environments

USE_CROSSBASE=		yes
USE_TOOLS+=		gm4 pod2man
USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-windres
CONFIGURE_ARGS+=	--enable-64-bit-bfd
CONFIGURE_ARGS+=	--enable-targets=all

# Ensure that --host is not included as default
CONFIGURE_ARGS+=	--target=i386-linux

MAKE_ARGS+=		CFLAGS="${CFLAGS}"
BUILD_TARGET=		all-binutils all-ld

PLIST_SUBST+=		LOCALBASE=${LOCALBASE:Q}

BINDIR=			${PREFIX}/libexec/binutils

# Prevent the need to run texi2pod.pl and pod2man hence
# the need for perl as build dependency.
post-patch:
.for _file_ in ld/ldver.texi ld/ld.1 gas/doc/gasver.texi gas/doc/as.1
	if [ -f ${WRKSRC}/${_file_} ]; then				\
		${TOUCH} ${WRKSRC}/${_file_};				\
	fi
.endfor
	${RM} -rf ${WRKSRC}/etc ${WRKSRC}/gas

# we use MKDIR, not INSTALL_PROGRAM_DIR, deliberately.
do-install:
	${MKDIR} ${BINDIR} ${PREFIX}/lib/ldscripts ${PREFIX}/include
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/addr2line ${BINDIR}
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/ar ${BINDIR}
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/coffdump ${BINDIR}
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/cxxfilt ${BINDIR}
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/nlmconv ${BINDIR}
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/nm-new ${BINDIR}/nm
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/objcopy ${BINDIR}
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/objdump ${BINDIR}
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/ranlib ${BINDIR}
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/readelf ${BINDIR}
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/size ${BINDIR}
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/srconv ${BINDIR}
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/strings ${BINDIR}
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/strip-new ${BINDIR}/strip
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/sysdump ${BINDIR}
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/sysinfo ${BINDIR}
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/windres ${BINDIR}
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/ld/ld-new ${BINDIR}/ld
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/nlmconv ${BINDIR}
	libtool --mode=install ${INSTALL_DATA} ${WRKSRC}/bfd/libbfd.la ${PREFIX}/lib
	libtool --mode=install ${INSTALL_DATA} ${WRKSRC}/intl/libintl.a ${PREFIX}/lib
	libtool --mode=install ${INSTALL_DATA} ${WRKSRC}/opcodes/libopcodes.la ${PREFIX}/lib
	libtool --mode=install ${INSTALL_DATA} ${WRKSRC}/libiberty/libiberty.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/include/ansidecl.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/symcat.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/bfd/bfd.h ${PREFIX}/include
	for f in ${WRKSRC}/ld/ldscripts/*; do ${INSTALL_DATA} $${f} ${PREFIX}/lib/ldscripts; done
	${INSTALL_SCRIPT} ${WRKSRC}/cross-env ${BINDIR}
	${LN} -s ${BINDIR}/cross-env ${LOCALBASE}/bin/cross-env

post-build:
	${SED} -e 's|@@PREFIX@@|${PREFIX}|' < ${FILESDIR}/cross-env > \
		${WRKSRC}/cross-env

.include "../../mk/bsd.pkg.mk"
