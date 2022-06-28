# $NetBSD: Makefile,v 1.12 2022/06/28 11:31:14 wiz Exp $
#
# GNU binutils snapshot, configured to target MIPS (NetBSD/playstation2)

BINUTILS_VER=		2.25

DISTNAME=		binutils-${BINUTILS_VER}
PKGNAME=		binutils-mips-${BINUTILS_VER}
PKGREVISION=		3
CATEGORIES=		cross lang
MASTER_SITES=		${MASTER_SITE_GNU:=binutils/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		martin@NetBSD.org
HOMEPAGE=		https://www.gnu.org/
COMMENT=		binutils for NetBSD/playstation2
PLATFORM=		mipsel--netbsd
LICENSE=		gnu-gpl-v3 AND gnu-lgpl-v3

BUILDLINK_TRANSFORM+=	rm:-Werror

USE_TOOLS+=		gm4 pod2man yacc gmake
USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--target=${PLATFORM}

MAKE_ARGS+=		CFLAGS="${CFLAGS}"

PLIST_SUBST+=		LOCALBASE=${PREFIX}

BINDIR=			${PREFIX}/bin

# Prevent the need to run texi2pod.pl and pod2man hence
# the need for perl as build dependency.
post-patch:
.for _file_ in ld/ldver.texi ld/ld.1 gas/doc/gasver.texi gas/doc/as.1
	if [ -f ${WRKSRC}/${_file_} ]; then				\
		${TOUCH} ${WRKSRC}/${_file_};				\
	fi
.endfor
	${RM} -rf ${WRKSRC}/etc

# we use MKDIR, not INSTALL_PROGRAM_DIR, deliberately.
do-install:
	${MKDIR} -p ${DESTDIR}${BINDIR} ${DESTDIR}${PREFIX}/lib/ldscripts ${DESTDIR}${PREFIX}/include
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/addr2line ${DESTDIR}${BINDIR}/${PLATFORM}-addr2line
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/gas/as-new ${DESTDIR}${BINDIR}/${PLATFORM}-as
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/ar ${DESTDIR}${BINDIR}/${PLATFORM}-ar
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/cxxfilt ${DESTDIR}${BINDIR}/${PLATFORM}-cxxfilt
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/nm-new ${DESTDIR}${BINDIR}/${PLATFORM}-nm
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/objcopy ${DESTDIR}${BINDIR}/${PLATFORM}-objcopy
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/objdump ${DESTDIR}${BINDIR}/${PLATFORM}-objdump
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/ranlib ${DESTDIR}${BINDIR}/${PLATFORM}-ranlib
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/readelf ${DESTDIR}${BINDIR}/${PLATFORM}-readelf
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/size ${DESTDIR}${BINDIR}/${PLATFORM}-size
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/strings ${DESTDIR}${BINDIR}/${PLATFORM}-strings
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/strip-new ${DESTDIR}${BINDIR}/${PLATFORM}-strip
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/sysinfo ${DESTDIR}${BINDIR}/${PLATFORM}-sysinfo
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/ld/ld-new ${DESTDIR}${BINDIR}/${PLATFORM}-ld
	for f in ${WRKSRC}/ld/ldscripts/*; do ${INSTALL_DATA} $${f} ${DESTDIR}${PREFIX}/lib/ldscripts; done

.include "../../mk/bsd.pkg.mk"
