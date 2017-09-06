# $NetBSD: Makefile,v 1.25 2017/09/06 09:03:00 wiz Exp $

DISTNAME=	xz-5.2.3
CATEGORIES=	archivers
MASTER_SITES=	https://tukaani.org/xz/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tukaani.org/xz/
COMMENT=	XZ utilities
LICENSE=	public-domain AND gnu-gpl-v2

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	src/liblzma/liblzma.pc.in

GCC_REQD+=		3.0

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
