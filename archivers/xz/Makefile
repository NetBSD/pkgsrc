# $NetBSD: Makefile,v 1.28 2018/09/02 21:03:22 maya Exp $

DISTNAME=	xz-5.2.4
CATEGORIES=	archivers
MASTER_SITES=	https://tukaani.org/xz/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tukaani.org/xz/
COMMENT=	General-purpose data compression software
LICENSE=	public-domain AND gnu-gpl-v2

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	src/liblzma/liblzma.pc.in

TEST_TARGET=		check

CONFLICTS=	lzma-[0-9]* lzma-utils-[0-9]* lzmalib-[0-9]*

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Msunpro)
CONFIGURE_ARGS+=	--disable-assembler
.endif

CONFIGURE_ENV.SunOS+=	ac_cv_have_decl_optreset=no
CONFIGURE_ENV.SunOS+=	gl_cv_cc_visibility=no

.include "options.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
