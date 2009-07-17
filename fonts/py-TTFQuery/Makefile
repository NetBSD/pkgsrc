# $NetBSD: Makefile,v 1.10 2009/07/17 11:27:59 joerg Exp $
#

DISTNAME=		TTFQuery-0.2.6
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		fonts python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ttfquery/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ttfquery.sourceforge.net/
COMMENT=		Query TTF font files for metadata and font outlines

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_ACCEPTED=	25 24

DEPENDS+=		${PYPKGPREFIX}-fonttools>=2.0b1:../../fonts/py-fonttools

PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
