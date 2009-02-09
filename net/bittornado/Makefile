# $NetBSD: Makefile,v 1.5 2009/02/09 22:56:25 joerg Exp $
#
PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

PKGREVISION=		1

CONFLICTS=		bittorrent-[0-9]*

PYDISTUTILSPKG=		yes

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../devel/py-cursespanel/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
