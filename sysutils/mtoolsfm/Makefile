# $NetBSD: Makefile,v 1.4 2003/05/05 19:05:19 jmmv Exp $
#

DISTNAME=	MToolsFM-1.9-3
PKGNAME=	mtoolsfm-1.9.3
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.core-coutainville.org/MToolsFM/archive/SOURCES/

MAINTAINER=	ben@wongs.net
HOMEPAGE=	http://www.core-coutainville.org/MToolsFM/
COMMENT=	Easy MS-DOS disk access without learning MS-DOS commands

DEPENDS+=	mtools>=3.9.7:../../sysutils/mtools

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-conffile=${PREFIX}/etc/mtoolsfm.conf

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
