# $NetBSD: Makefile,v 1.48 2024/03/29 18:19:30 wiz Exp $

DISTNAME=	xz-5.4.6
PKGNAME=	xz-5.6.1
PKGREVISION=	100
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=tukaani-project/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tukaani.org/xz/
COMMENT=	General-purpose data compression software (5.4)
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
