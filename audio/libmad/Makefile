# $NetBSD: Makefile,v 1.25 2024/03/16 16:23:22 nia Exp $

DISTNAME=	libmad-0.15.1b
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mad/}

MAINTAINER=	simonb@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/mad/
COMMENT=	High-quality MPEG audio decoder
LICENSE=	gnu-gpl-v2

CONFLICTS=	mad<0.15

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

INSTALLATION_DIRS=	lib/pkgconfig

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_ARCH:Mmips64*)
# Disable MIPS-specific ASM on MIPS64 due to:
# error: impossible constraint in 'asm'
CONFIGURE_ARGS+=	--enable-fpm=64bit
CONFIGURE_ARGS+=	--disable-aso
.endif

post-build:
	${SED}	-e 's,@PREFIX@,${PREFIX},g'				\
		-e 's,@VERSION@,${PKGVERSION},g'			\
		-e 's|@COMPILER_RPATH_FLAG@|${COMPILER_RPATH_FLAG:Q}|g'	\
		< ${FILESDIR}/mad.pc.in > ${WRKDIR}/mad.pc

post-install:
	${INSTALL_DATA} ${WRKDIR}/mad.pc ${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../mk/bsd.pkg.mk"
