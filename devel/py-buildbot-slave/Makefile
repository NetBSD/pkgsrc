# $NetBSD: Makefile,v 1.6 2014/05/09 07:37:00 wiz Exp $

DISTNAME=		buildbot-slave-0.8.8
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
EGG_NAME=		buildbot_slave-0.8.8
CATEGORIES=		devel net python
MASTER_SITES=		http://buildbot.googlecode.com/files/

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://buildbot.net/
COMMENT=		Buildbot slave
LICENSE=		gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-twisted

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
