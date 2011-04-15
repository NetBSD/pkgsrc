# $NetBSD: Makefile,v 1.13 2011/04/15 13:43:13 adam Exp $

DISTNAME=	pexpect-2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pexpect/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://pexpect.sourceforge.net/
COMMENT=	Pure Python Expect-like module
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG= yes
NO_CONFIGURE=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
