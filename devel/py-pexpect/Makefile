# $NetBSD: Makefile,v 1.1.1.1 2004/02/23 16:25:02 minskim Exp $

DISTNAME=	pexpect-0.99
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
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
