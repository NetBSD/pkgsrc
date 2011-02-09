# $NetBSD: Makefile,v 1.8 2011/02/09 09:12:16 adam Exp $

DISTNAME=	xz-5.0.1
CATEGORIES=	archivers
MASTER_SITES=	http://tukaani.org/xz/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tukaani.org/xz/
COMMENT=	XZ utilities
LICENSE=	public-domain AND gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE=	src/liblzma/liblzma.pc.in

GCC_REQD=		3.4

CONFLICTS=	lzma-[0-9]* lzma-utils-[0-9]* lzmalib-[0-9]*

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Msunpro)
CONFIGURE_ARGS+=	--disable-assembler
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
