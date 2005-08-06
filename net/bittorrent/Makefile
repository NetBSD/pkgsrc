# $NetBSD: Makefile,v 1.29 2005/08/06 10:55:06 wiz Exp $
#

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/BitT/bitt/}
PKGREVISION=	1

PYDISTUTILSPKG=	YES

CONFLICTS+=	bittornado-[0-9]*

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../devel/py-cursespanel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
