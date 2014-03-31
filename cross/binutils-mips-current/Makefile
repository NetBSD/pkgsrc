# $NetBSD: Makefile,v 1.1 2014/03/31 09:46:57 martin Exp $
#
# GNU binutils snapshot, configured to target MIPS (NetBSD/playstation2)

BINUTILS_VER=		2.23.91

DISTNAME=		binutils-${BINUTILS_VER}
# PKGREVISION=		1
PKGNAME=		binutils-mips-${BINUTILS_VER}
CATEGORIES=		cross lang
MASTER_SITES=		ftp://sourceware.org/pub/binutils/snapshots/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		martin@NetBSD.org
HOMEPAGE=		http://www.gnu.org/
COMMENT=		binutils for NetBSD/playstation2
LICENSE=		gnu-gpl-v3 AND gnu-lgpl-v3

BUILDLINK_TRANSFORM+=	rm:-Werror

USE_TOOLS+=		gm4 pod2man yacc
USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-64-bit-bfd
CONFIGURE_ARGS+=	--target=mips--netbsdelf

MAKE_ARGS+=		CFLAGS="${CFLAGS}"

PLIST_SUBST+=		LOCALBASE=${LOCALBASE:Q}

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
PFX=mips--netbsdelf
do-install:
	${MKDIR} ${DESTDIR}${BINDIR} ${DESTDIR}${PREFIX}/lib/ldscripts ${DESTDIR}${PREFIX}/include
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/addr2line ${DESTDIR}${BINDIR}/${PFX}-addr2line
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/gas/as-new ${DESTDIR}${BINDIR}/${PFX}-as
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/ar ${DESTDIR}${BINDIR}/${PFX}-ar
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/cxxfilt ${DESTDIR}${BINDIR}/${PFX}-cxxfilt
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/nm-new ${DESTDIR}${BINDIR}/${PFX}-nm
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/objcopy ${DESTDIR}${BINDIR}/${PFX}-objcopy
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/objdump ${DESTDIR}${BINDIR}/${PFX}-objdump
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/ranlib ${DESTDIR}${BINDIR}/${PFX}-ranlib
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/readelf ${DESTDIR}${BINDIR}/${PFX}-readelf
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/size ${DESTDIR}${BINDIR}/${PFX}-size
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/strings ${DESTDIR}${BINDIR}/${PFX}-strings
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/strip-new ${DESTDIR}${BINDIR}/${PFX}-strip
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/binutils/sysinfo ${DESTDIR}${BINDIR}/${PFX}-sysinfo
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/ld/ld-new ${DESTDIR}${BINDIR}/${PFX}-ld
	for f in ${WRKSRC}/ld/ldscripts/*; do ${INSTALL_DATA} $${f} ${DESTDIR}${PREFIX}/lib/ldscripts; done

.include "../../mk/bsd.pkg.mk"
