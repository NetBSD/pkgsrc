# $NetBSD: Makefile,v 1.2 2004/07/22 09:16:01 recht Exp $
#

DISTNAME=		TTFQuery-0.2.6
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		fonts python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ttfquery/}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://ttfquery.sourceforge.net/
COMMENT=		Query TTF font files for metadata and font outlines

DEPENDS+=		${PYPKGPREFIX}-fonttools>=2.0b1:../../fonts/py-fonttools

USE_BUILDLINK3=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
