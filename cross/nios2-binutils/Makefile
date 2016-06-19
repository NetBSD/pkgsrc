# $NetBSD: Makefile,v 1.15 2016/06/19 16:23:59 wiz Exp $

DISTNAME=		binutils-2.24
PKGNAME=		${DISTNAME:S/^/nios2-/}
PKGREVISION=		3
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_GNU:=binutils/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/binutils/
COMMENT=		GNU binutils for Altera FPGA Nios2 processor
LICENSE=		gnu-gpl-v3

# No need to use makeinfo - this package doesn't install the documentation.
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_GNU_CONFIGURE_HOST=	no
INFO_FILES=		# empty

# follows to devel/binutils
# PR pkg/48504, ksh is sufficient for NetBSD 5.2 and NetBSD 6.1
.include "../../mk/bsd.prefs.mk"
.if !empty(MACHINE_PLATFORM:MNetBSD-[5-6].*-*) && \
       empty(MACHINE_PLATFORM:MNetBSD-6.99.*-*)
USE_TOOLS+=	       ksh
CONFIG_SHELL=	       ksh
.endif

.include		"options.mk"

NIOS2_TARGET=		nios2-elf
CONFIGURE_ARGS+=	--disable-werror --target=${NIOS2_TARGET} --disable-nls
PLIST_SUBST+=		NIOS2_TARGET=${NIOS2_TARGET:Q}

GNU_CONFIGURE_PREFIX=	${PREFIX}/cross
PATH:=			${PREFIX}/cross/bin:${PATH}
AUTO_MKDIRS=		yes

# following file installed is reference only, not used at all for the moment
post-install:
	${INSTALL_DATA} files/nios2elf-netbsd.x ${DESTDIR}${PREFIX}/cross/${NIOS2_TARGET}/lib/ldscripts

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
