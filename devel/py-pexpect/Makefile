# $NetBSD: Makefile,v 1.5 2006/02/05 23:08:51 joerg Exp $

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
NO_CONFIGURE=   yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
