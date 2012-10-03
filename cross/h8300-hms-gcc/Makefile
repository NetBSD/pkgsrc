# $NetBSD: Makefile,v 1.27 2012/10/03 00:10:30 asau Exp $

DISTNAME=		gcc-core-3.1
PKGNAME=		cross-h8300-hms-gcc-3.1
PKGREVISION=		6
CATEGORIES=		cross
MASTER_SITES=		ftp://ftp.gnu.org/gnu/gcc/gcc-3.1/ \
			ftp://sources.redhat.com/pub/newlib/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			${DISTNAME:S/-core-/-g++-/}${EXTRACT_SUFX} \
			newlib-1.10.0.tar.gz

PATCH_SITES=		${MASTER_SITE_SOURCEFORGE:=h8300-hms/}
PATCHFILES=		h8300-hms-gcc-3.1-1.patch
PATCH_DIST_ARGS=	-d ${SRCDIR} -E -p1

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		#empty
COMMENT=		GCC compiler for h8300-hms

DEPENDS+=	cross-h8300-hms-binutils-[0-9]*:../../cross/h8300-hms-binutils

H8300_PREFIX=		${LOCALBASE}/libexec/cross-h8300-hms

WRKSRC=			${WRKDIR}/objdir
USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${H8300_PREFIX:Q}
CONFIGURE_ARGS+=	--infodir=${H8300_PREFIX}/gcc
CONFIGURE_ARGS+=	--target=h8300-hms
CONFIGURE_ARGS+=	--enable-languages=c,c++
CONFIGURE_ARGS+=	--with-newlib
CONFIGURE_SCRIPT=	${SRCDIR}/configure
SRCDIR=			${WRKDIR}/gcc-3.1
MAKE_ENV+=		SHELL=${CONFIG_SHELL}
BUILD_TARGET=		CFLAGS="-O2 -fomit-frame-pointer" all
INSTALLATION_DIRS+=	bin libexec/cross-h8300-hms/h8300-hms/bin
INFO_FILES=		# PLIST

GCC_REQD+=		2.8.0

post-extract:
	${LN} -s ${WRKDIR}/newlib-1.10.0/newlib ${SRCDIR}/newlib
	${MKDIR} ${WRKSRC}

post-install:
	for f in h8300-hms-cpp    h8300-hms-gcc \
		 h8300-hms-c++    h8300-hms-g++ \
		 h8300-hms-gccbug h8300-hms-gcov \
		 ; do \
		${LN} -s ../libexec/cross-h8300-hms/bin/"$$f" \
			${DESTDIR}${PREFIX}/bin/"$$f" || exit 1; \
	done

.include "../../mk/bsd.pkg.mk"
