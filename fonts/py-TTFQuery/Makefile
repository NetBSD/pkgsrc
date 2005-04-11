# $NetBSD: Makefile,v 1.3 2005/04/11 21:45:47 tv Exp $
#

DISTNAME=		TTFQuery-0.2.6
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		fonts python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ttfquery/}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://ttfquery.sourceforge.net/
COMMENT=		Query TTF font files for metadata and font outlines

DEPENDS+=		${PYPKGPREFIX}-fonttools>=2.0b1:../../fonts/py-fonttools

PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
