# $NetBSD: Makefile,v 1.1.1.1 2002/06/27 22:29:09 dmcmahill Exp $

DISTNAME=		gcc-core-3.1
PKGNAME=		cross-h8300-hms-gcc-3.1
CATEGORIES=		cross
MASTER_SITES=		ftp://ftp.gnu.org/gnu/gcc/gcc-3.1/ \
			ftp://sources.redhat.com/pub/newlib/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} newlib-1.10.0.tar.gz

PATCH_SITES=		http://telia.dl.sourceforge.net/sourceforge/h8300-hms/
PATCHFILES=		h8300-hms-gcc-3.1-1.patch
PATCH_DIST_ARGS=	-d ${SRCDIR} -E -p1

MAINTAINER=		oishi@ims.ac.jp
HOMEPAGE=		#empty
COMMENT=		gcc compiler for h8300-hms

DEPENDS+=		cross-h8300-hms-binutils-*:../../cross/h8300-hms-binutils

USE_GMAKE=		yes
INSTALL_SUBDIR=		libexec/cross-h8300-hms
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${LOCALBASE}/${INSTALL_SUBDIR}
CONFIGURE_ARGS+=	--infodir=${LOCALBASE}/${INSTALL_SUBDIR}/gcc
CONFIGURE_ARGS+=	--target=h8300-hms
CONFIGURE_ARGS+=	--enable-languages=c
CONFIGURE_ARGS+=	--with-newlib
CONFIGURE_SCRIPT=	${SRCDIR}/configure
SRCDIR=			${WRKDIR}/gcc-3.1
WRKSRC=			${WRKDIR}/objdir
ALL_TARGET=		CFLAGS="-O2 -fomit-frame-pointer" all

post-extract:
	${LN} -s ${WRKDIR}/newlib-1.10.0/newlib ${SRCDIR}/newlib
	${MKDIR} ${WRKSRC}

post-install:
	for f in h8300-hms-cpp    h8300-hms-gcc \
		 h8300-hms-gccbug h8300-hms-gcov ; do \
		${LN} -s ../${INSTALL_SUBDIR}/bin/$$f ${LOCALBASE}/bin/$$f ; \
	done

GCC_VERSION!=           gcc --version
.if (${GCC_VERSION:C/-.*$$//} == egcs)
# "egcs" cannot be used, as this package tickles c++ compiler bugs
.include "../../lang/gcc/Makefile.gcc"
.endif

.include "../../mk/bsd.pkg.mk"
