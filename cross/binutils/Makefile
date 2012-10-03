# $NetBSD: Makefile,v 1.55 2012/10/03 00:10:29 asau Exp $
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
LICENSE=		gnu-gpl-v2 AND gnu-lgpl-v2

BUILDLINK_TRANSFORM+=	rm:-Werror

USE_CROSSBASE=		yes
USE_TOOLS+=		gm4 pod2man yacc
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
	${MKDIR} ${DESTDIR}${BINDIR} ${DESTDIR}${PREFIX}/lib/ldscripts ${DESTDIR}${PREFIX}/include
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/addr2line ${DESTDIR}${BINDIR}
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/ar ${DESTDIR}${BINDIR}
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/coffdump ${DESTDIR}${BINDIR}
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/cxxfilt ${DESTDIR}${BINDIR}
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/nlmconv ${DESTDIR}${BINDIR}
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/nm-new ${DESTDIR}${BINDIR}/nm
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/objcopy ${DESTDIR}${BINDIR}
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/objdump ${DESTDIR}${BINDIR}
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/ranlib ${DESTDIR}${BINDIR}
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/readelf ${DESTDIR}${BINDIR}
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/size ${DESTDIR}${BINDIR}
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/srconv ${DESTDIR}${BINDIR}
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/strings ${DESTDIR}${BINDIR}
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/strip-new ${DESTDIR}${BINDIR}/strip
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/sysdump ${DESTDIR}${BINDIR}
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/sysinfo ${DESTDIR}${BINDIR}
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/windres ${DESTDIR}${BINDIR}
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/ld/ld-new ${DESTDIR}${BINDIR}/ld
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/nlmconv ${DESTDIR}${BINDIR}
	libtool --mode=install ${INSTALL_DATA} ${WRKSRC}/bfd/libbfd.la ${DESTDIR}${PREFIX}/lib
	libtool --mode=install ${INSTALL_DATA} ${WRKSRC}/intl/libintl.a ${DESTDIR}${PREFIX}/lib
	libtool --mode=install ${INSTALL_DATA} ${WRKSRC}/opcodes/libopcodes.la ${DESTDIR}${PREFIX}/lib
	libtool --mode=install ${INSTALL_DATA} ${WRKSRC}/libiberty/libiberty.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/include/ansidecl.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/symcat.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/bfd/bfd.h ${DESTDIR}${PREFIX}/include
	for f in ${WRKSRC}/ld/ldscripts/*; do ${INSTALL_DATA} $${f} ${DESTDIR}${PREFIX}/lib/ldscripts; done
	${INSTALL_SCRIPT} ${WRKSRC}/cross-env ${DESTDIR}${BINDIR}

post-build:
	${SED} -e 's|@@PREFIX@@|${PREFIX}|' < ${FILESDIR}/cross-env > \
		${WRKSRC}/cross-env

.include "../../mk/bsd.pkg.mk"
