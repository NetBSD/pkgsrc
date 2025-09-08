# $NetBSD: Makefile,v 1.3 2025/09/08 22:54:47 lloyd Exp $

DISTNAME=	binutils-2.45
PKGNAME=	cross-riscv64-none-elf-${DISTNAME}
#PKGREVISION=	1
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GNU:=binutils/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	port-riscv@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Cross binutils for bare metal RISC-V 64-bit ELF
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

USE_LANGUAGES+=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		bison gmake makeinfo perl
GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no # several sub-configures know --enable-nls

TOOL_DEPENDS+=		gtexinfo>=5.1:../../devel/gtexinfo
_TOOLS_USE_PKGSRC.makeinfo=	yes

RISCV64ELF_PREFIX=	${PREFIX}/cross-riscv64-none-elf

OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure
GNU_CONFIGURE_PREFIX=	${RISCV64ELF_PREFIX}

CONFIGURE_ARGS+=	--disable-werror
CONFIGURE_ARGS+=	--target=riscv64-none-elf
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--enable-deterministic-archives
INFO_FILES=		yes

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

post-install:
	${RM} ${DESTDIR}${RISCV64ELF_PREFIX}/riscv64-none-elf/lib/ldscripts/stamp

.include "../../mk/bsd.pkg.mk"
