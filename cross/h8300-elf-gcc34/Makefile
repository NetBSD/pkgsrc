# $NetBSD: Makefile,v 1.3 2013/05/06 07:11:25 ryoon Exp $

DISTNAME=		gcc-core-3.4.6
PKGNAME=		cross-h8300-elf-${DISTNAME:S/-core//}
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/gcc-3.4.6/}
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			${DISTNAME:S/-core-/-g++-/}${EXTRACT_SUFX} \
			newlib-${NEWLIBVER}${EXTRACT_SUFX}
NEWLIBVER=		1.14.0
SITES.newlib-${NEWLIBVER}.tar.gz=	ftp://sources.redhat.com/pub/newlib/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		#empty
COMMENT=		GCC compiler for h8300-elf

DEPENDS+=	cross-h8300-elf-binutils-[0-9]*:../../cross/h8300-elf-binutils

WRKSRC=			${WRKDIR}/${DISTNAME:S/-core//}

H8300_PREFIX=		${PREFIX}/cross-h8300-elf
OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure

USE_TOOLS+=		gmake makeinfo
GNU_CONFIGURE=		yes

GNU_CONFIGURE_PREFIX=	${H8300_PREFIX}

CONFIGURE_ARGS+=	--target=h8300-elf
CONFIGURE_ARGS+=	--enable-languages=c,c++
CONFIGURE_ARGS+=	--disable-multilib
CONFIGURE_ARGS+=	--with-newlib
MAKE_ENV+=		SHELL=${CONFIG_SHELL}
INFO_FILES=		yes

INSTALLATION_DIRS+=	bin

GCC_REQD+=		2.8.0

post-extract:
	${LN} -s ${WRKDIR}/newlib-${NEWLIBVER}/newlib ${WRKSRC}/newlib

pre-configure:
	${MKDIR} ${WRKSRC}/${OBJDIR}
	${CP} ${PKGSRCDIR}/mk/gnu-config/config.guess ${WRKSRC}
	${CP} ${PKGSRCDIR}/mk/gnu-config/config.sub ${WRKSRC}

post-install:
	for f in h8300-elf-cpp    h8300-elf-gcc \
		 h8300-elf-c++    h8300-elf-g++ \
		 h8300-elf-gccbug h8300-elf-gcov \
		 ; do \
		${LN} -s ../cross-h8300-elf/bin/"$$f" \
			${DESTDIR}${PREFIX}/bin/"$$f" || exit 1; \
	done

.include "../../mk/bsd.pkg.mk"
