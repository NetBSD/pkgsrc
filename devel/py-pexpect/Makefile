# $NetBSD: Makefile,v 1.9 2007/11/19 10:14:31 tron Exp $

DISTNAME=	pexpect-2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pexpect/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://pexpect.sourceforge.net/
COMMENT=	Pure Python Expect-like module

PYDISTUTILSPKG= yes
PYTHON_VERSIONS_ACCEPTED=	24 23 22 21
NO_CONFIGURE=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
