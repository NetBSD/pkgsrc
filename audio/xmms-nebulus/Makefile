# $NetBSD: Makefile,v 1.17 2008/03/16 12:35:05 obache Exp $
#

DISTNAME=	xmms-nebulus-0.8.0
CATEGORIES=	xmms audio
MASTER_SITES=	http://nebulus.tuxfamily.org/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nebulus.tuxfamily.org/
COMMENT=	Xmms plugin that uses OpenGL

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		msgfmt
GNU_CONFIGURE=		YES

.include "../../audio/xmms/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
