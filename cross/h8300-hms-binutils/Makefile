# $NetBSD: Makefile,v 1.1.1.1 2002/06/27 22:24:36 dmcmahill Exp $

DISTNAME=		binutils-2.12.1
PKGNAME=		cross-h8300-hms-binutils-2.12.1
CATEGORIES=		cross
MASTER_SITES=		ftp://ftp.gnu.org/gnu/binutils/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		oishi@ims.ac.jp
HOMEPAGE=		#empty
COMMENT=		h8300-hms cross utility

INSTALL_SUBDIR=		libexec/cross-h8300-hms
USE_GMAKE=		yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${LOCALBASE}/${INSTALL_SUBDIR}
CONFIGURE_ARGS+=	--infodir=${LOCALBASE}/${INSTALL_SUBDIR}/binutils
CONFIGURE_ARGS+=	--target=h8300-hms
CONFIGURE_SCRIPT=	${SRCDIR}/configure
SRCDIR=			${WRKDIR}/${DISTNAME}
WRKSRC=			${WRKDIR}/objdir
ALL_TARGET=		CFLAGS="-O2 -fomit-frame-pointer" all

post-extract:
	${MKDIR} ${WRKSRC}

pre-install:
	${MKDIR} ${LOCALBASE}/${INSTALL_SUBDIR}

post-install:
	for f in h8300-hms-size      h8300-hms-objdump h8300-hms-ar \
		 h8300-hms-strings   h8300-hms-ranlib  h8300-hms-objcopy \
		 h8300-hms-srconv    h8300-hms-sysdump h8300-hms-coffdump \
		 h8300-hms-addr2line h8300-hms-readelf h8300-hms-nm \
		 h8300-hms-strip     h8300-hms-c++filt h8300-hms-as \
		 h8300-hms-gasp      h8300-hms-ld ; do \
	${LN} -s ../${INSTALL_SUBDIR}/bin/$$f ${LOCALBASE}/bin/$$f ; \
	done
	${MV} ${LOCALBASE}/${INSTALL_SUBDIR}/lib/libiberty.a \
	      ${LOCALBASE}/${INSTALL_SUBDIR}/lib/libiberty_binutils.a

.include "../../mk/bsd.pkg.mk"
