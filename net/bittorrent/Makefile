# $NetBSD: Makefile,v 1.35 2006/02/26 22:43:33 tron Exp $

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/BitT/bitt/}

PYDISTUTILSPKG=	yes

CONFLICTS+=	bittornado-[0-9]*
CONFLICTS+=	BitTornado-[0-9]*

.include "../../mk/bsd.prefs.mk"

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../devel/py-cursespanel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
