# $NetBSD: Makefile,v 1.5 2005/02/22 15:35:56 adam Exp $

DISTNAME=	Codeville-0.1.10
PKGNAME=	codeville-0.1.10
CATEGORIES=	devel
MASTER_SITES=	http://codeville.org/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://codeville.org/
COMMENT=	Distributed revision control system

USE_BUILDLINK3=		yes
PYDISTUTILSPKG=		yes

# XXX we don't need threads, but db3 is linked against libread
PYTHON_VERSIONS_ACCEPTED= 23

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../databases/py-bsddb3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
