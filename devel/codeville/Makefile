# $NetBSD: Makefile,v 1.3 2004/10/03 00:13:25 tv Exp $
#

DISTNAME=		Codeville-0.1.8
PKGNAME=		codeville-0.1.8
PKGREVISION=	1
CATEGORIES=		devel
MASTER_SITES=		http://codeville.org/download/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://codeville.org/
COMMENT=		Distributed revision control system

USE_BUILDLINK3=		yes
PYDISTUTILSPKG=		yes

# XXX we don't need threads, but db3 is linked against libpthread
PYTHON_VERSIONS_ACCEPTED= 23pth

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../databases/py-bsddb3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
