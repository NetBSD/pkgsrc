# $NetBSD: Makefile,v 1.1.1.1 2004/02/19 00:22:41 minskim Exp $
#

DISTNAME=		fonttools-2.0b1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		fonts
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fonttools/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://fonttools.sourceforge.net/
COMMENT=		Library for manipulating fonts

WRKSRC=			${WRKDIR}/fonttools
USE_BUILDLINK3=		yes
PY_PATCHPLIST=		yes
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
