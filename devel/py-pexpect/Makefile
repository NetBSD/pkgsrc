# $NetBSD: Makefile,v 1.8 2007/02/22 19:26:24 wiz Exp $

DISTNAME=	pexpect-0.999
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pexpect/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://pexpect.sourceforge.net/
COMMENT=	Pure Python Expect-like module

PYDISTUTILSPKG= yes
PYTHON_VERSIONS_ACCEPTED=	24 23 22 21
NO_CONFIGURE=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
