# $NetBSD: Makefile,v 1.13 2007/02/17 20:59:47 wiz Exp $

DISTNAME=	Codeville-0.1.16
PKGNAME=	codeville-0.1.16
CATEGORIES=	devel scm
MASTER_SITES=	http://codeville.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://codeville.org/
COMMENT=	Distributed revision control system

PYDISTUTILSPKG=		yes

# XXX we don't need threads, but db3 is linked against libpthread
PYTHON_VERSIONS_ACCEPTED= 23 24

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../databases/py-bsddb3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
