# $NetBSD: Makefile,v 1.37 2009/02/09 22:56:26 joerg Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/BitT/bitt/}
PKGREVISION=	1

PYDISTUTILSPKG=	yes

CONFLICTS+=	bittornado-[0-9]*
CONFLICTS+=	BitTornado-[0-9]*

.include "../../mk/bsd.prefs.mk"

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../devel/py-cursespanel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
