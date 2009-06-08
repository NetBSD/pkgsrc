# $NetBSD: Makefile,v 1.1.1.1 2009/06/08 14:01:18 wiz Exp $
#

DISTNAME=	xz-4.999.8beta
CATEGORIES=	archivers
MASTER_SITES=	http://tukaani.org/xz/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tukaani.org/xz/
COMMENT=	XZ utilities
#LICENSE=	public-domain AND gnu-gpl-v2 AND gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE=	src/liblzma/liblzma.pc.in

CONFLICTS=	lzma-utils-[0-9]*

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
