# $NetBSD: Makefile,v 1.7 2011/06/19 13:46:29 plunky Exp $
#
PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

PKGREVISION=		3

CONFLICTS=		bittorrent-[0-9]*

PYDISTUTILSPKG=		yes

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../devel/py-cursespanel/buildlink3.mk"
.include "../../security/py-amkCrypto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
