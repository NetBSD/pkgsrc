# $NetBSD: Makefile,v 1.3 2004/11/25 19:54:46 minskim Exp $

DISTNAME=	pexpect-0.999
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pexpect/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://pexpect.sourceforge.net/
COMMENT=	Pure Python Expect-like module

PYDISTUTILSPKG= yes
USE_BUILDLINK3= yes
NO_CONFIGURE=   yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
