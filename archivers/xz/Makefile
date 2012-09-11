# $NetBSD: Makefile,v 1.14 2012/09/11 19:47:03 asau Exp $

DISTNAME=	xz-5.0.4
CATEGORIES=	archivers
MASTER_SITES=	http://tukaani.org/xz/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tukaani.org/xz/
COMMENT=	XZ utilities
LICENSE=	public-domain AND gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE=	src/liblzma/liblzma.pc.in

GCC_REQD=		3.4

CONFLICTS=	lzma-[0-9]* lzma-utils-[0-9]* lzmalib-[0-9]*

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Msunpro)
CONFIGURE_ARGS+=	--disable-assembler
.endif

.if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=		ac_cv_have_decl_optreset=no
CONFIGURE_ENV+=		gl_cv_cc_visibility=no
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
