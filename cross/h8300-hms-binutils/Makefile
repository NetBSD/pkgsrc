# $NetBSD: Makefile,v 1.9 2004/12/03 15:14:53 wiz Exp $

DISTNAME=		binutils-2.12.1
PKGNAME=		cross-h8300-hms-binutils-2.12.1
CATEGORIES=		cross
MASTER_SITES=		ftp://ftp.gnu.org/gnu/binutils/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		oishi@ims.ac.jp
HOMEPAGE=		# empty
COMMENT=		h8300-hms cross utility

H8300_PREFIX=		${PREFIX}/libexec/cross-h8300-hms

WRKSRC=			${WRKDIR}/objdir
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_MAKEINFO=		yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${H8300_PREFIX}
CONFIGURE_ARGS+=	--infodir=${H8300_PREFIX}/binutils
CONFIGURE_ARGS+=	--target=h8300-hms
CONFIGURE_SCRIPT=	${SRCDIR}/configure
SRCDIR=			${WRKDIR}/${DISTNAME}
BUILD_TARGET=		CFLAGS="-O2 -fomit-frame-pointer" all
INFO_DIR=		libexec/cross-h8300-hms/binutils
INFO_FILES=		as.info bfd.info binutils.info configure.info
INFO_FILES+=		gasp.info ld.info standards.info

post-extract:
	${MKDIR} ${WRKSRC}

pre-install:
	${MKDIR} ${H8300_PREFIX}

post-install:
	for f in h8300-hms-size      h8300-hms-objdump h8300-hms-ar \
		 h8300-hms-strings   h8300-hms-ranlib  h8300-hms-objcopy \
		 h8300-hms-srconv    h8300-hms-sysdump h8300-hms-coffdump \
		 h8300-hms-addr2line h8300-hms-readelf h8300-hms-nm \
		 h8300-hms-strip     h8300-hms-c++filt h8300-hms-as \
		 h8300-hms-gasp      h8300-hms-ld ; do \
		${LN} -s ${H8300_PREFIX}/bin/$$f ${PREFIX}/bin/$$f; \
	done
	${MV} ${H8300_PREFIX}/lib/libiberty.a \
	      ${H8300_PREFIX}/lib/libiberty_binutils.a

.include "../../mk/bsd.pkg.mk"
