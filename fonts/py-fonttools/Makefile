# $NetBSD: Makefile,v 1.7 2005/12/08 09:23:14 rillig Exp $
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
