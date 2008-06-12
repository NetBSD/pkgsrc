# $NetBSD: Makefile,v 1.4 2008/06/12 02:14:38 joerg Exp $
#
PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

CONFLICTS=		bittorrent-[0-9]*

PYDISTUTILSPKG=		yes

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../devel/py-cursespanel/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
