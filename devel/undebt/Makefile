# $NetBSD: Makefile,v 1.2 2019/04/25 07:32:50 maya Exp $

DISTNAME=	undebt-0.2.2
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=u/undebt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Yelp/undebt
COMMENT=	Fast, reliable tool for performing automated code refactoring
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-argparse-[0-9]*:../../devel/py-argparse
DEPENDS+=	${PYPKGPREFIX}-pyparsing-[0-9]*:../../devel/py-pyparsing

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
