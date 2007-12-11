# $NetBSD: Makefile,v 1.10 2007/12/11 22:54:04 heinz Exp $

DISTNAME=	pexpect-2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pexpect/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://pexpect.sourceforge.net/
COMMENT=	Pure Python Expect-like module

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG= yes
PYTHON_VERSIONS_ACCEPTED=	24 23 22 21
NO_CONFIGURE=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
