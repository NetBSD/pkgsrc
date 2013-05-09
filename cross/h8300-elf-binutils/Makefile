# $NetBSD: Makefile,v 1.2 2013/05/09 13:47:25 joerg Exp $

DISTNAME=	binutils-2.19.1
PKGNAME=	cross-h8300-elf-${DISTNAME}
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GNU:=binutils/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Cross utility for h8300-elf

H8300_PREFIX=	${PREFIX}/cross-h8300-elf

USE_TOOLS+=	gmake makeinfo
GNU_CONFIGURE=	yes

OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure
GNU_CONFIGURE_PREFIX=	${H8300_PREFIX}

CONFIGURE_ARGS+=	--disable-werror --target=h8300-elf
INFO_FILES=		yes

INSTALLATION_DIRS+=	bin ${H8300_PREFIX}

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}
	${CP} ${PKGSRCDIR}/mk/gnu-config/config.guess ${WRKSRC}
	${CP} ${PKGSRCDIR}/mk/gnu-config/config.sub ${WRKSRC}


post-install:
	for f in h8300-elf-addr2line	h8300-elf-ar \
		 h8300-elf-as		h8300-elf-c++filt \
		 h8300-elf-gprof	h8300-elf-ld \
		 h8300-elf-nm		h8300-elf-objcopy \
		 h8300-elf-objdump	h8300-elf-ranlib \
		 h8300-elf-readelf	h8300-elf-size \
		 h8300-elf-strings	h8300-elf-strip ; do \
		${LN} -s ${H8300_PREFIX}/bin/"$$f" \
		  ${DESTDIR}${PREFIX}/bin/"$$f" || exit 1; \
	done
	${MV} ${DESTDIR}${H8300_PREFIX}/lib/libiberty.a \
	      ${DESTDIR}${H8300_PREFIX}/lib/libiberty_binutils.a

.include "../../mk/bsd.pkg.mk"
