# $NetBSD: Makefile,v 1.4 2009/09/18 13:18:54 sketch Exp $
#

DISTNAME=	xz-4.999.9beta
CATEGORIES=	archivers
MASTER_SITES=	http://tukaani.org/xz/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tukaani.org/xz/
COMMENT=	XZ utilities
LICENSE=	public-domain AND gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE=	src/liblzma/liblzma.pc.in

CONFLICTS=	lzma-[0-9]* lzma-utils-[0-9]* lzmalib-[0-9]*

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Msunpro)
CONFIGURE_ARGS+=	--disable-assembler
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
