# $NetBSD: Makefile,v 1.7 2003/09/17 19:40:06 grant Exp $

DISTNAME=		gcc-core-3.1
PKGNAME=		cross-h8300-hms-gcc-3.1
WRKSRC=			${WRKDIR}/objdir
CATEGORIES=		cross
MASTER_SITES=		ftp://ftp.gnu.org/gnu/gcc/gcc-3.1/ \
			ftp://sources.redhat.com/pub/newlib/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} newlib-1.10.0.tar.gz

PATCH_SITES=		http://telia.dl.sourceforge.net/sourceforge/h8300-hms/
PATCHFILES=		h8300-hms-gcc-3.1-1.patch
PATCH_DIST_ARGS=	-d ${SRCDIR} -E -p1

MAINTAINER=		oishi@ims.ac.jp
HOMEPAGE=		#empty
COMMENT=		GCC compiler for h8300-hms

DEPENDS+=	cross-h8300-hms-binutils-[0-9]*:../../cross/h8300-hms-binutils

H8300_PREFIX=		${LOCALBASE}/libexec/cross-h8300-hms

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${H8300_PREFIX}
CONFIGURE_ARGS+=	--infodir=${H8300_PREFIX}/gcc
CONFIGURE_ARGS+=	--target=h8300-hms
CONFIGURE_ARGS+=	--enable-languages=c
CONFIGURE_ARGS+=	--with-newlib
CONFIGURE_SCRIPT=	${SRCDIR}/configure
SRCDIR=			${WRKDIR}/gcc-3.1
ALL_TARGET=		CFLAGS="-O2 -fomit-frame-pointer" all

USE_PKGSRC_GCC=		# defined

post-extract:
	${LN} -s ${WRKDIR}/newlib-1.10.0/newlib ${SRCDIR}/newlib
	${MKDIR} ${WRKSRC}

post-install:
	for f in h8300-hms-cpp    h8300-hms-gcc \
		 h8300-hms-gccbug h8300-hms-gcov ; do \
		${LN} -s ${H8300_PREFIX}/bin/$$f ${PREFIX}/bin/$$f ; \
	done

.include "../../mk/bsd.pkg.mk"
