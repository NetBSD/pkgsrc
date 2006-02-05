# $NetBSD: Makefile,v 1.9 2006/02/05 23:09:11 joerg Exp $
#

DISTNAME=		fonttools-2.0b1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		fonts python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fonttools/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://fonttools.sourceforge.net/
COMMENT=		Library for manipulating fonts

WRKSRC=			${WRKDIR}/fonttools
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.if !empty(PYPKGPREFIX:M*pth)
PLIST_SUBST+=		FONTTOOLSPTH=""
.else
PLIST_SUBST+=		FONTTOOLSPTH="@comment "
.endif

.include "../../math/py-Numeric/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
