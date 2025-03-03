# $NetBSD: Makefile,v 1.12 2025/03/03 20:29:27 wiz Exp $

VER=		1.0
DISTNAME=	sendmail-admin-${VER}
PKGNAME=	${PYPKGPREFIX}-sendmail-admin-${VER}
PKGREVISION=	3
CATEGORIES=	mail python
MASTER_SITES=	http://www.clapper.org/software/python/sendmail-admin/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.clapper.org/software/python/sendmail-admin/
COMMENT=	Mailqs and rmmq, two scripts that ease Sendmail administration
LICENSE=	2-clause-bsd

PYTHON_SELF_CONFLICT=		yes

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
