# $NetBSD: Makefile,v 1.11 2008/04/25 20:31:10 tnn Exp $

DISTNAME=	pexpect-2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pexpect/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://pexpect.sourceforge.net/
COMMENT=	Pure Python Expect-like module

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG= yes
PYTHON_VERSIONS_ACCEPTED=	25 24 23
NO_CONFIGURE=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
