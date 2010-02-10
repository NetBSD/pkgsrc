# $NetBSD: Makefile,v 1.6 2010/02/10 19:17:43 joerg Exp $
#
PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

PKGREVISION=		2

CONFLICTS=		bittorrent-[0-9]*

PYDISTUTILSPKG=		yes

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../devel/py-cursespanel/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
