# $NetBSD: Makefile,v 1.3 2004/07/22 09:16:01 recht Exp $
#

DISTNAME=		fonttools-2.0b1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		fonts python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fonttools/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://fonttools.sourceforge.net/
COMMENT=		Library for manipulating fonts

WRKSRC=			${WRKDIR}/fonttools
USE_BUILDLINK3=		yes
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
