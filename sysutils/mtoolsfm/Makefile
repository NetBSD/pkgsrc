# $NetBSD: Makefile,v 1.1.1.1.2.2 2002/06/23 19:00:25 jlam Exp $
#

DISTNAME=	MToolsFM-1.9-3
PKGNAME=	mtoolsfm-1.9.3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.core-coutainville.org/MToolsFM/archive/SOURCES/

MAINTAINER=	ben@wongs.net
HOMEPAGE=	http://www.core-coutainville.org/MToolsFM/
COMMENT=	Easy MS-DOS disk access without learning MS-DOS commands

DEPENDS+=	mtools>=3.9.7:../../sysutils/mtools

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-conffile=${PREFIX}/etc/mtoolsfm.conf

.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
