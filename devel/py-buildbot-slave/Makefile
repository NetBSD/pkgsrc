# $NetBSD: Makefile,v 1.3 2012/10/31 11:19:28 asau Exp $
#

DISTNAME=		buildbot-slave-0.8.5
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
EGG_NAME=		buildbot_slave-0.8.5
CATEGORIES=		devel net python
MASTER_SITES=		http://buildbot.googlecode.com/files/

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://buildbot.net/
COMMENT=		Buildbot slave
LICENSE=		gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
