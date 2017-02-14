# $NetBSD: Makefile,v 1.11 2017/02/14 10:26:28 wiz Exp $

DISTNAME=		buildbot-slave-0.8.8
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel net python
MASTER_SITES=		http://buildbot.googlecode.com/files/

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://buildbot.net/
COMMENT=		Buildbot slave
LICENSE=		gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # as of 0.8.8

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
