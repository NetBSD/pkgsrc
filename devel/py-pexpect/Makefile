# $NetBSD: Makefile,v 1.2 2004/07/22 09:16:01 recht Exp $

DISTNAME=	pexpect-0.99
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
