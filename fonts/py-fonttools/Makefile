# $NetBSD: Makefile,v 1.5 2005/07/27 16:21:17 wiz Exp $
#

DISTNAME=		fonttools-2.0b1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		fonts python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fonttools/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://fonttools.sourceforge.net/
COMMENT=		Library for manipulating fonts

WRKSRC=			${WRKDIR}/fonttools
PYDISTUTILSPKG=		yes

PLIST_SUBST+=		FONTTOOLSPTH=${FONTTOOLSPTH}

.include "../../lang/python/extension.mk"
.if !empty(PYPKGPREFIX:M*pth)
FONTTOOLSPTH=	""
.else
FONTTOOLSPTH=	"@comment "
.endif

.include "../../math/py-Numeric/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
