# $NetBSD: Makefile,v 1.6 2005/04/11 21:45:19 tv Exp $

DISTNAME=	Codeville-0.1.10
PKGNAME=	codeville-0.1.10
CATEGORIES=	devel
MASTER_SITES=	http://codeville.org/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://codeville.org/
COMMENT=	Distributed revision control system

PYDISTUTILSPKG=		yes

# XXX we don't need threads, but db3 is linked against libread
PYTHON_VERSIONS_ACCEPTED= 23

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../databases/py-bsddb3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
